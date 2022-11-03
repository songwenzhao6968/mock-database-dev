//
// Created by Xiaoyuan Liu on 11/19/20.
// Edited by Songwen Zhao on 11/01/22.
//

#include <regex>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <sstream>

#include "database.h"

Field::Field(DataType t) : type(t) {}

std::string Field::as_string() { return ""; }

IntField::IntField(int v, DataType t) : value(v), Field(t) {}

IntField::IntField(int v) : value(v), Field(INT32) {}

void IntField::set(int v) { this->value = v; }

int IntField::get() const { return this->value; }

std::string IntField::as_string() {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

UintField::UintField(uint v, DataType t) : value(v), Field(t) {}

UintField::UintField(uint v) : value(v), Field(UINT32) {}

void UintField::set(uint v) { this->value = v; }

uint UintField::get() const { return this->value; }

std::string UintField::as_string() {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

StrField::StrField(std::string v) : value(std::move(v)), Field(STR) {}

void StrField::set(const std::string &v) { this->value = v; }

std::string StrField::get() const { return this->value; }

std::string StrField::as_string() {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

BoolField::BoolField(bool v, DataType t) : value(v), Field(t) {}

BoolField::BoolField(bool v) : value(v), Field(BOOL) {}

void BoolField::set(bool v) { this->value = v; }

bool BoolField::get() const { return this->value; }

std::string BoolField::as_string() {
    return value?"true":"false";
}

Schema::Schema(json &j) {
    static std::unordered_map<std::string, DataType> s_to_t{
            {"str",    STR},
            {"bool", BOOL},
            {"uint8",  UINT8},
            {"uint32", UINT32},
            {"int16",  INT16},
            {"int32",  INT16}
    };
    for (auto &j_f: j["field"]) {
        auto col_name = j_f.at(0).get<std::string>();
        auto col_type = j_f.at(1).get<std::string>();
        columns.emplace_back(std::make_pair(col_name, s_to_t.at(col_type)));
    }
    for (auto &el: j["key"].items()) {
        if (el.value().get<std::string>() == "primary") primary_key = el.key();
    }
}

size_t Schema::length() const { return this->columns.size(); }

size_t Schema::find_column_by_name(std::string name) const {
    if (name == "*") return find_column_by_name(primary_key);
    for (int i = 0; i < columns.size(); ++i) if (columns.at(i).first == name) return i;
    throw "Column not found.";
}

Record::Record(const Schema &s, json &j) : table(nullptr) {
    size_t schema_length = s.length();
    for (int i = 0; i < schema_length; ++i) {
        Field *f;
        auto j_cur = j.at(i);
        switch (s.columns.at(i).second) {
            case STR:
                f = new StrField(j_cur.get<std::string>());
                break;
            case BOOL:
                f = new BoolField(j_cur.get<bool>());
                break;
            case UINT8:
                f = new UintField(j_cur.get<uint>(), UINT8);
                break;
            case UINT32:
                f = new UintField(j_cur.get<uint>(), UINT32);
                break;
            case INT16:
                f = new IntField(j_cur.get<int>(), INT16);
                break;
            case INT32:
                f = new IntField(j_cur.get<int>(), INT32);
                break;
            default:
                break;
        }
        this->fields.emplace_back(f);
    }
}

Record::Record(const Record &rhs) : table(rhs.table) {
    size_t schema_length = rhs.fields.size();
    for (int i = 0; i < schema_length; ++i) {
        Field *f;
        Field *f_rhs = rhs.fields.at(i);
        switch (f_rhs->type) {
            case STR:
                f = new StrField(static_cast<StrField *>(f_rhs)->get());
                break;
            case BOOL:
                f = new BoolField(static_cast<BoolField *>(f_rhs)->get());
                break;
            case UINT8:
            case UINT32:
                f = new UintField(static_cast<UintField *>(f_rhs)->get(), f_rhs->type);
                break;
            case INT16:
            case INT32:
                f = new IntField(static_cast<UintField *>(f_rhs)->get(), f_rhs->type);
                break;
            default:
                break;
        }
        this->fields.emplace_back(f);
    }
}

Record::~Record() {
    for (auto &p: this->fields) {
        delete p;
    }
}

size_t Record::find_column_by_name(std::string name) const {
    return this->table->schema->find_column_by_name(name);
}

std::string Record::as_string(const std::vector<std::string> &concerned_columns) const {
    std::stringstream ss;
    for (auto &col_name: concerned_columns) {
        Field *f = fields.at(find_column_by_name(col_name));
        ss << f->as_string() << "\t";
    }
    return ss.str();
}

Table::Table() : database(nullptr), schema(nullptr), records() {}

void Table::insert(const Record &r) {
    Record r_new = r;
    r_new.table = this;
    this->records.push_back(r_new);
    // TODO: maintain primary key?
}

Table::Table(json &j) : database(nullptr), schema(new Schema(j["schema"])) {
    size_t limit = 0x7fffffff;
    if (j.contains("limit")) limit = j["limit"].get<size_t>();
    for (auto &j_r: j["data"]) {
        this->insert(Record(*schema, j_r));
        if (size() >= limit) break;
    }
}

size_t Table::size() { return this->records.size(); }

void Table::reset() {
    this->records.clear();
    delete schema;
}

Table::~Table() { this->reset(); }

std::string replace_all(std::string old, std::string s, std::string t) {
    std::regex re("(" + s + ")");
    return std::regex_replace(old, re, t);
}

Predicate::Predicate(PredicateType t, size_t l, size_t r) : type(t), p_l(l), p_r(r) {}

Predicate::Predicate(PredicateType t, std::string concerned_column): type(t), concerned_column(concerned_column) {}

Predicate::Predicate(PredicateType t, std::string concerned_column, std::string value) :
        type(t), concerned_column(concerned_column), value(value) {}

bool Predicate::check(const Record &r) const {
    if (type == P_AND) {
        return predicates->at(p_l).check(r) && predicates->at(p_r).check(r);
    }
    if (type == P_OR) return predicates->at(p_l).check(r) || predicates->at(p_r).check(r);
    if (type == P_IN) {
        Field *f = r.fields.at(r.find_column_by_name(concerned_column));
        switch (f->type) {
            case STR: {
                std::string lhs = static_cast<StrField *>(f)->get();
                return column_string_values.find(lhs) != column_string_values.end();
            }
            case BOOL: {
                bool lhs = static_cast<BoolField *>(f)->get();
                return column_bool_values.find(lhs) != column_bool_values.end();
            }
            case UINT8:
            case UINT32: {
                uint lhs = static_cast<UintField *>(f)->get();
                return column_uint_values.find(lhs) != column_uint_values.end();
            }
            case INT16:
            case INT32: {
                uint lhs = static_cast<UintField *>(f)->get();
                return column_int_values.find(lhs) != column_int_values.end();
            }
            default: {
                throw "Unsupported predicate for unknown field";
            }
        }
    }
    // other ops
    // 1. find column
    Field *f = r.fields.at(r.find_column_by_name(concerned_column)); // record in the given column
    switch (f->type) {
        case STR: {
            std::string lhs = static_cast<StrField *>(f)->get();
            std::string rhs = value.substr(1, value.size() - 2); // removing quote marks
            switch (type) {
                case P_NE:
                    return lhs != rhs;
                case P_EQ:
                    return lhs == rhs;
                default:
                    throw "Unsupported predicate for StrField";
            }
        }
        case BOOL: {
            bool lhs = static_cast<BoolField *>(f)->get();
            bool rhs = value=="true"?true:false;
            switch (type) {
                case P_EQ:
                    return lhs == rhs;
                case P_NE:
                    return lhs != rhs;
                default:
                    throw "Unsupported predicate for BoolField";
            }
        }
        case UINT8:
        case UINT32: {
            //std::cout<<"yes."<<std::endl;
            uint lhs = static_cast<UintField *>(f)->get();
            uint rhs = std::stoul(value);
            switch (type) {
                case P_G:
                    return lhs > rhs;
                case P_GE:
                    return lhs >= rhs;
                case P_EQ:
                    return lhs == rhs;
                case P_NE:
                    return lhs != rhs;
                case P_LE:
                    return lhs <= rhs;
                case P_L:
                    return lhs < rhs;
                default:
                    throw "INVALID TYPE (should never be triggered)";
            }
        }
        case INT16:
        case INT32: {
            uint lhs = static_cast<UintField *>(f)->get();
            uint rhs = std::stoi(value);
            switch (type) {
                case P_G:
                    return lhs > rhs;
                case P_GE:
                    return lhs >= rhs;
                case P_EQ:
                    return lhs == rhs;
                case P_NE:
                    return lhs != rhs;
                case P_LE:
                    return lhs <= rhs;
                case P_L:
                    return lhs < rhs;
                default:
                    throw "INVALID TYPE (should never be triggered)";
            }
        }
        default:
            throw "Unsupported predicate for unknown field";
    }
}

void Predicate::dump() const {
    // print all information about a predicate
    switch (type) {
        case P_AND:
        case P_OR: {
            predicates->at(p_l).dump();
            std::cout << " AND/OR " << std::endl;
            predicates->at(p_r).dump();
            std::cout << std::endl;
            break;
        }
        case P_IN: {
            std::cout << this->concerned_column << "\n IN \n";
            for (const auto& column_value : column_string_values) {
                std::cout << column_value << ", ";
            }
            std::cout << std::endl;
            break;
        }
        default: {
            // operation that compares concerned_column with value
            std::cout << this->concerned_column << " compare with " <<
            this->value << std::endl;
        };

    }
}


bool Query::isAggregation() const {
    return (this->type > Q_AGGREGATE_) && (this->type < Q_AGGREGATE__);
}

bool Query::isRetrieval() const {
    return this->type == Q_RETRIEVE;
}

Query::Query(std::string SQL) {
    if (use_antlr) {
        throw "Antlr is not working";
    } else {
        // 1. separate different parts
        SQL = replace_all(SQL, "\\(", " ( ");
        SQL = replace_all(SQL, "\\)", " ) ");
        SQL = replace_all(SQL, ",", " , ");
        // potential bug here: if the matched string (inside quote) contains such characters,
        // the white space might be changed and the matching result will be wrong
        // solution: later switch to a standard parser (e.g. antlr based)
        std::regex ws_re("\\s+");
        auto temp_tokens = std::vector<std::string>(
                std::sregex_token_iterator(SQL.begin(), SQL.end(), ws_re, -1),
                std::sregex_token_iterator()
        );
        this->tokens.clear();
        // merge tokens inside quote mark
        bool on_hold = false;
        std::string current = "";
        for (auto &token: temp_tokens) {
            if (token[0] == '"') {
                on_hold = true;
            }
            if (!on_hold) {
                this->tokens.emplace_back(token);
            } else {
                if (current.size() == 0) {
                    current = token;
                } else {
                    current = current + " " + token;
                }
            }
            if (token[token.size() - 1] == '"') {
                on_hold = false;
                this->tokens.emplace_back(current);
                current = "";
            }
        }
        // 2. figure out query type
        this->type = Q_UNKNOWN;
        if (tokens.at(0) == "USE") {
            this->type = Q_USE_CONTEXT;
            this->context = tokens.at(1);
            return;
        }
        for (int i = 0; i < tokens.size(); ++i) {
            std::string _token = tokens.at(i);
            // std::cout << "*" + _token + "*" << std::endl;
            std::transform(_token.begin(), _token.end(), _token.begin(), (int (*)(int)) std::toupper);
            if (_token == "SELECT") {
                select_l = i + 1;
            } else if (_token == "FROM") {
                select_r = i;
                from_l = i + 1; // keep both for handling special format in future
            } else if (_token == "WHERE") {
                from_r = i;
                where_l = i + 1;
            } else if (_token == "EXIST") {
                this->type = Q_AGGREGATE_EXIST;
            } else if (_token == "COUNT") {
                this->type = Q_AGGREGATE_CNT;
            } else if (_token == "MIN") {
                this->type = Q_AGGREGATE_MIN;
            } else if (_token == "MAX") {
                this->type = Q_AGGREGATE_MAX;
            } else if (_token == "AVG") {
                this->type = Q_AGGREGATE_AVG;
            } else if (_token == "SUM") {
                this->type = Q_AGGREGATE_SUM;
            } else if (_token == "AVG_CLOSING_PRICE"){
                this->type = Q_AGGREGATE_AVG_CP;
            } else if (_token == "COUNT_UNIQUE"){
                this->type = Q_AGGREGATE_CNT_UNQ;
            }
        }
        if (this->type == Q_UNKNOWN) this->type = Q_RETRIEVE;
        where_r = tokens.size();
        // 3. list columns in select
        bool expecting_brackets = this->isAggregation();
        if (expecting_brackets)
            for (int i = select_l; i < select_r; ++i) {
                std::string &token = tokens.at(i);
                if (token == ")") {
                    select_r = i;
                } else if (token == "(") {
                    select_l = i + 1;
                }
            }
        for (int i = select_l; i < select_r; ++i) {
            std::string &token = tokens.at(i);
            if (token == ",") continue;
            concerned_columns.emplace_back(token);
        }
        // 4. "from"
        if (from_r - from_l > 1) std::cerr << "WARNING: please check the FROM clause." << std::endl;
        concerned_table = tokens.at(from_l);
        // 5. parse predicate tree in WHERE clause
        predicates.emplace_back(generate_predicates(where_l, where_r));
        // 6. [later] reorder predicates into DNF: (a and b and c) or (e and f) or ...
    }
}

Predicate Query::generate_predicates(size_t l, size_t r) {
    static std::unordered_map<std::string, PredicateType> s_to_p{
            {"AND", P_AND},
            {"OR",  P_OR},
            {">=",  P_GE},
            {">",   P_G},
            {"=",   P_EQ},
            {"!=",  P_NE},
            {"<=",  P_LE},
            {"<",   P_L},
            {"IN",  P_IN}
    };
    // remove brackets
    int bracket_cnt = 0;
    bool ever_zero = false;
    for (int i = l; i < r; ++i) {
        std::string &token = tokens.at(i);
        if (token == "(") {
            ++bracket_cnt;
        } else if (token == ")") {
            --bracket_cnt;
        }
        if (i < r - 1 && bracket_cnt == 0) {
            ever_zero = true;
            break;
        }
    }
    if (!ever_zero) return generate_predicates(l + 1, r - 1);
    // OR
    for (int i = l; i < r; ++i) {
        std::string &token = tokens.at(i);
        std::string _token = token;
        std::transform(_token.begin(), _token.end(), _token.begin(), (int (*)(int)) std::toupper);
        if (token == "(") {
            ++bracket_cnt;
        } else if (token == ")") {
            --bracket_cnt;
        } else if (bracket_cnt == 0 && s_to_p.count(_token)) {
            if (_token == "OR") {
                Predicate p_l = generate_predicates(l, i);
                size_t p_l_id = predicates.size();
                predicates.emplace_back(p_l);
                Predicate p_r = generate_predicates(i + 1, r);
                size_t p_r_id = predicates.size();
                predicates.emplace_back(p_r);
                Predicate p = Predicate(s_to_p.at(_token), p_l_id, p_r_id);
                p.predicates = &predicates;
                return p;
            }
        }
    }
    // AND
    for (int i = l; i < r; ++i) {
        std::string &token = tokens.at(i);
        std::string _token = token;
        std::transform(_token.begin(), _token.end(), _token.begin(), (int (*)(int)) std::toupper);
        if (token == "(") {
            ++bracket_cnt;
        } else if (token == ")") {
            --bracket_cnt;
        } else if (bracket_cnt == 0 && s_to_p.count(_token)) {
            if (_token == "AND") {
                Predicate p_l = generate_predicates(l, i);
                size_t p_l_id = predicates.size();
                predicates.emplace_back(p_l);
                Predicate p_r = generate_predicates(i + 1, r);
                size_t p_r_id = predicates.size();
                predicates.emplace_back(p_r);
                Predicate p = Predicate(s_to_p.at(_token), p_l_id, p_r_id);
                p.predicates = &predicates;
                return p;
            }
        }
    }
    // other ops, should be Column, Op, Value, or a set
    assert(r - l == 3);
    Predicate p = Predicate(s_to_p.at(tokens.at(l + 1)), tokens.at(l), tokens.at(l + 2));
    p.predicates = &predicates;
    return p;
}

size_t Query::getRootPredicateId() const {
    return predicates.size() - 1;
}

Predicate &Query::getRootPredicate() {
    return predicates.at(getRootPredicateId());
}

bool Query::filter(const Record &r) const {
    return predicates.at(getRootPredicateId()).check(r);
}

Query::Query(QueryType type): type(type) {}


void Query::dump() {
    // print all information about the query, for debug use
    if (type == Q_USE_CONTEXT) return;
    std::cout << this->concerned_table << std::endl;
    for (const auto & concerned_column : this->concerned_columns) {
        std::cout << concerned_column << " ";
    }
    std::cout << std::endl << this->type << std::endl;
    getRootPredicate().dump();
}

void Database::addTable(std::string name, Table *t) {
    this->tables[name] = t;
    t->database = this;
}

std::string Database::runQuery(const Query &q) {
    std::string ret = "";
    switch (q.type) {
        case Q_USE_CONTEXT:
            if (q.context == "SECURE") return "WARN\nUSING INSECURE DATABASE IMPLEMENTATION";
            if (q.context == "INSECURE") return "INFO\nBASELINE INSECURE DATABASE USED";
        case Q_RETRIEVE:
            ret = "RET\n";
            for (auto &r: tables.at(q.concerned_table)->records) {
                if (q.filter(r)) {
                    ret += r.as_string(q.concerned_columns) + "\n";
                }
            }
            return ret;
        case Q_AGGREGATE_EXIST:
        case Q_AGGREGATE_CNT:
        case Q_AGGREGATE_AVG:
        case Q_AGGREGATE_SUM:
        case Q_AGGREGATE_MAX:
        case Q_AGGREGATE_MIN: {
            long long _cnt = 0;
            long long _sum = 0;
            long long _max = 0x8000000000000000;
            long long _min = 0x7fffffffffffffff;
            assert(q.concerned_columns.size() == 1);
            const std::string &concerned_column = q.concerned_columns.at(0);
            for (auto &r: tables.at(q.concerned_table)->records) {
                if (q.filter(r)) {
                    size_t col_idx = r.find_column_by_name(concerned_column);
                    Field *f = r.fields.at(col_idx);
                    ++_cnt;
                    assert(f->type > NUM_TYPE_);
                    assert(f->type < NUM_TYPE__);
                    if (f->type < UNSIGN_BOUND_) {
                        int value = static_cast<UintField *>(f)->get();
                        _sum += value;
                        _max = std::max(_max, (long long) value);
                        _min = std::min(_min, (long long) value);
                    } else {
                        int value = static_cast<IntField *>(f)->get();
                        _sum += value;
                        _max = std::max(_max, (long long) value);
                        _min = std::min(_min, (long long) value);
                    }
                }
            }
            std::stringstream ss;
            switch (q.type) {
                case Q_AGGREGATE_EXIST:
                    ss << "AGG\n" << (_cnt > 0) << "\n";
                    break;
                case Q_AGGREGATE_CNT:
                    ss << "AGG\n" << _cnt << "\n";
                    break;
                case Q_AGGREGATE_AVG:
                    ss << "AGG\n" << (double) _sum / _cnt << "\n";
                    break;
                case Q_AGGREGATE_SUM:
                    ss << "AGG\n" << _sum << "\n";
                    break;
                case Q_AGGREGATE_MAX:
                    ss << "AGG\n" << _max << "\n";
                    break;
                case Q_AGGREGATE_MIN:
                    ss << "AGG\n" << _min << "\n";
                    break;
                default:
                    return "ERR\nUNKNOWN AGGREGATION TYPE";
            }
            return ss.str();
        }
        case Q_AGGREGATE_AVG_CP: {
            long long _sum[4] = {0, 0, 0, 0};
            assert(q.concerned_columns.size() == 1);
            assert(q.concerned_columns.at(0) == "*");
            std::vector<std::string> concerned_columns{"volume_for_buy", "volume_for_sell", "price_for_buy", "price_for_sell"};
            for (auto &r: tables.at(q.concerned_table)->records) {
                if (q.filter(r)) {
                    for (int i = 0; i < 4; ++i) {
                        size_t col_idx = r.find_column_by_name(concerned_columns.at(i));
                        Field *f = r.fields.at(col_idx);
                        assert(f->type > NUM_TYPE_);
                        assert(f->type < NUM_TYPE__);
                        if (f->type < UNSIGN_BOUND_) {
                            int value = static_cast<UintField *>(f)->get();
                            _sum[i] += value;
                        } else {
                            int value = static_cast<IntField *>(f)->get();
                            _sum[i] += value;
                        }
                    }
                }
            }
            if (_sum[0]+_sum[1] == 0)
                return "ERR\nRECORD NOT EXIST";
            std::stringstream ss;
            ss << "AGG\n" << (_sum[2]+_sum[3])/(_sum[0]+_sum[1]) << "\n";
            return ss.str();
        }
        default:
            return "ERR\nUNKNOWN QUERY TYPE";
    }
    return "ERR\nQUERY TYPE NOT SUPPORTED";
}
