//
// Created by Xiaoyuan Liu on 11/18/20.
// Edited by Songwen Zhao on 11/01/22.
//

#ifndef MULTIPARTY_DATABASE_DATABASE_H
#define MULTIPARTY_DATABASE_DATABASE_H

#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <json.hpp>

using json = nlohmann::json;

enum DataType {
    // basic set
    STR,BOOL,CHAR,
    NUM_TYPE_,
    UINT8, UINT32,
    UNSIGN_BOUND_,
    INT16, INT32,
    NUM_TYPE__
};

class Schema {
    std::string primary_key;
public:
    std::vector<std::pair<std::string , DataType> > columns;
    explicit Schema(json& j);
    size_t length() const;
    size_t find_column_by_name(std::string name) const;
};

class Field {
public:
    DataType type;
    explicit Field(DataType t);
    virtual std::string as_string();
};

class IntField:public Field {
    int value;
public:
    IntField(int v);
    IntField(int v, DataType t);
    int get() const;
    void set(int v);
    std::string as_string() override;
};

class UintField:public Field {
    uint value;
public:
    UintField(uint v);
    UintField(uint v, DataType t);
    uint get() const;
    void set(uint v);
    std::string as_string() override;
};

class StrField:public Field {
    std::string value;
public:
    StrField(std::string v);
    std::string get() const;
    void set(const std::string& v);
    std::string as_string();
};

class Table;

class Record {
public:
    Table* table;
    std::vector<Field*> fields;
    Record(const Schema& s, json& j);
    Record(const Record& rhs);
    Record& operator=(const Record& rhs) = delete;
    ~Record();
    size_t find_column_by_name(std::string name) const;
    std::string as_string(const std::vector<std::string>& concerned_columns) const;
};

class Database;

class Table {
public:
    Database* database;
    std::vector<Record> records;
    Schema* schema; // notice: table class is not responsible for maintaining memory of the schema
    Table();
    ~Table();
    explicit Table(json& j);
    void insert(const Record& r);
    void reset();
    size_t size();
};

enum PredicateType {
    P_EQ,
    P_NE,
    P_G,
    P_GE,
    P_L,
    P_LE,
    P_AND,
    P_OR,
    P_IN
};

class Predicate { // predicates tree
public:
    std::vector<Predicate>* predicates;
    PredicateType type;
    std::string concerned_column;
    std::unordered_set<std::string> column_string_values; // for in-operation
    std::unordered_set<int> column_int_values;
    std::unordered_set<uint> column_uint_values;
    std::string value; // value to compare with <concerned_column>
    size_t p_l;
    size_t p_r;
    Predicate(PredicateType t, std::string concerned_column, std::string value);
    Predicate(PredicateType t, std::string concerned_column);
    Predicate(PredicateType t, size_t l, size_t r);
    bool check(const Record& r) const;
    void dump() const;
};

enum QueryType {
    Q_UNKNOWN,
    Q_USE_CONTEXT,
    Q_RETRIEVE,
    Q_AGGREGATE_,
    Q_AGGREGATE_EXIST,  // not "EXISTS", this is not standard SQL
    Q_AGGREGATE_CNT,
    Q_AGGREGATE_SUM,
    Q_AGGREGATE_AVG,
    Q_AGGREGATE_MAX,
    Q_AGGREGATE_MIN,
    Q_AGGREGATE__,
};

class Query {
public:
    QueryType type;
    static const bool use_antlr = false;
    std::string context;
    std::vector<std::string> tokens;
    std::vector<Predicate> predicates;
    size_t select_l, select_r;
    size_t from_l, from_r;
    size_t where_l, where_r;
    std::vector<std::string> concerned_columns;
    std::string concerned_table;
    Query(QueryType type);
    Query(std::string SQL);
    Predicate generate_predicates(size_t l, size_t r);
    bool filter(const Record& r) const;
    bool isAggregation() const;
    bool isRetrieval() const;
    void dump();
    size_t getRootPredicateId() const;
    Predicate& getRootPredicate ();
};

// Database contains many tables, and you can run query on a database.

class Database {
protected:
    std::unordered_map<std::string, Table*> tables; // a simple list of table and its name
public:
    // notice: Database class is not responsible for maintaining memory of these tables
    void addTable(std::string name, Table* t);
    std::string runQuery(const Query& q);
};

#endif //MULTIPARTY_DATABASE_DATABASE_H
