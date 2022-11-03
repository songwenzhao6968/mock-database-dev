
// Generated from ./src/parser/mysql.g4 by ANTLR 4.11.1


#include "mysqlVisitor.h"

#include "mysqlParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MysqlParserStaticData final {
  MysqlParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MysqlParserStaticData(const MysqlParserStaticData&) = delete;
  MysqlParserStaticData(MysqlParserStaticData&&) = delete;
  MysqlParserStaticData& operator=(const MysqlParserStaticData&) = delete;
  MysqlParserStaticData& operator=(MysqlParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mysqlParserOnceFlag;
MysqlParserStaticData *mysqlParserStaticData = nullptr;

void mysqlParserInitialize() {
  assert(mysqlParserStaticData == nullptr);
  auto staticData = std::make_unique<MysqlParserStaticData>(
    std::vector<std::string>{
      "sql_stmt_list", "sql_stmt", "use_stmt", "select_stmt", "expr", "primary_expr", 
      "literal_value", "aggregate_func", "unary_operator", "result", "result_column", 
      "schema_name", "table_name", "column_name", "column_value", "any_name"
    },
    std::vector<std::string>{
      "", "';'", "','", "'*'", "'/'", "'%'", "'+'", "'-'", "'<<'", "'>>'", 
      "'&'", "'|'", "'<'", "'<='", "'>'", "'>='", "'='", "'=='", "'!='", 
      "'('", "')'", "'~'", "'.'", "'IN'", "'SELECT'", "'FROM'", "'WHERE'", 
      "", "", "'not'", "'USE'", "'SECURE'", "'INSECURE'", "'COUNT'", "'MAX'", 
      "'MIN'", "'SUM'", "'AVG'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "IN", "SELECT", "FROM", "WHERE", "AND", "OR", 
      "NOT", "USE", "SECURE", "INSECURE", "COUNT", "MAX", "MIN", "SUM", 
      "AVG", "IDENTIFIER", "DECIMAL_LITERAL", "STRING_LITERAL", "SINGLE_LINE_COMMENT", 
      "MULTILINE_COMMENT", "SPACES"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,43,170,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,4,0,35,8,0,11,0,12,0,36,1,0,5,0,40,8,0,10,0,12,0,
  	43,9,0,1,0,5,0,46,8,0,10,0,12,0,49,9,0,1,0,1,0,1,1,1,1,3,1,55,8,1,1,2,
  	1,2,1,2,1,2,3,2,61,8,2,1,3,1,3,1,3,1,3,5,3,67,8,3,10,3,12,3,70,9,3,1,
  	3,1,3,1,3,1,3,3,3,76,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	5,4,89,8,4,10,4,12,4,92,9,4,1,4,1,4,3,4,96,8,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,119,
  	8,4,10,4,12,4,122,9,4,1,5,1,5,1,5,1,5,1,5,3,5,129,8,5,1,6,1,6,1,7,1,7,
  	1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,143,8,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,3,10,151,8,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,3,15,168,8,15,1,15,0,1,8,16,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,0,8,1,0,3,5,1,0,6,7,1,0,8,11,1,0,12,15,1,0,
  	16,18,1,0,38,40,1,0,33,37,3,0,6,7,21,21,29,29,177,0,32,1,0,0,0,2,54,1,
  	0,0,0,4,60,1,0,0,0,6,62,1,0,0,0,8,95,1,0,0,0,10,128,1,0,0,0,12,130,1,
  	0,0,0,14,132,1,0,0,0,16,134,1,0,0,0,18,142,1,0,0,0,20,150,1,0,0,0,22,
  	152,1,0,0,0,24,154,1,0,0,0,26,156,1,0,0,0,28,158,1,0,0,0,30,167,1,0,0,
  	0,32,41,3,2,1,0,33,35,5,1,0,0,34,33,1,0,0,0,35,36,1,0,0,0,36,34,1,0,0,
  	0,36,37,1,0,0,0,37,38,1,0,0,0,38,40,3,2,1,0,39,34,1,0,0,0,40,43,1,0,0,
  	0,41,39,1,0,0,0,41,42,1,0,0,0,42,47,1,0,0,0,43,41,1,0,0,0,44,46,5,1,0,
  	0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,50,1,0,0,
  	0,49,47,1,0,0,0,50,51,5,0,0,1,51,1,1,0,0,0,52,55,3,6,3,0,53,55,3,4,2,
  	0,54,52,1,0,0,0,54,53,1,0,0,0,55,3,1,0,0,0,56,57,5,30,0,0,57,61,5,31,
  	0,0,58,59,5,30,0,0,59,61,5,32,0,0,60,56,1,0,0,0,60,58,1,0,0,0,61,5,1,
  	0,0,0,62,63,5,24,0,0,63,68,3,18,9,0,64,65,5,2,0,0,65,67,3,18,9,0,66,64,
  	1,0,0,0,67,70,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,70,68,
  	1,0,0,0,71,72,5,25,0,0,72,75,3,24,12,0,73,74,5,26,0,0,74,76,3,8,4,0,75,
  	73,1,0,0,0,75,76,1,0,0,0,76,7,1,0,0,0,77,78,6,4,-1,0,78,96,3,10,5,0,79,
  	80,3,16,8,0,80,81,3,8,4,9,81,96,1,0,0,0,82,83,3,26,13,0,83,84,5,23,0,
  	0,84,85,5,19,0,0,85,90,3,28,14,0,86,87,5,2,0,0,87,89,3,28,14,0,88,86,
  	1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,90,
  	1,0,0,0,93,94,5,20,0,0,94,96,1,0,0,0,95,77,1,0,0,0,95,79,1,0,0,0,95,82,
  	1,0,0,0,96,120,1,0,0,0,97,98,10,8,0,0,98,99,7,0,0,0,99,119,3,8,4,9,100,
  	101,10,7,0,0,101,102,7,1,0,0,102,119,3,8,4,8,103,104,10,6,0,0,104,105,
  	7,2,0,0,105,119,3,8,4,7,106,107,10,5,0,0,107,108,7,3,0,0,108,119,3,8,
  	4,6,109,110,10,4,0,0,110,111,7,4,0,0,111,119,3,8,4,5,112,113,10,3,0,0,
  	113,114,5,27,0,0,114,119,3,8,4,4,115,116,10,2,0,0,116,117,5,28,0,0,117,
  	119,3,8,4,3,118,97,1,0,0,0,118,100,1,0,0,0,118,103,1,0,0,0,118,106,1,
  	0,0,0,118,109,1,0,0,0,118,112,1,0,0,0,118,115,1,0,0,0,119,122,1,0,0,0,
  	120,118,1,0,0,0,120,121,1,0,0,0,121,9,1,0,0,0,122,120,1,0,0,0,123,129,
  	3,12,6,0,124,125,5,19,0,0,125,126,3,8,4,0,126,127,5,20,0,0,127,129,1,
  	0,0,0,128,123,1,0,0,0,128,124,1,0,0,0,129,11,1,0,0,0,130,131,7,5,0,0,
  	131,13,1,0,0,0,132,133,7,6,0,0,133,15,1,0,0,0,134,135,7,7,0,0,135,17,
  	1,0,0,0,136,143,3,20,10,0,137,138,3,14,7,0,138,139,5,19,0,0,139,140,3,
  	20,10,0,140,141,5,20,0,0,141,143,1,0,0,0,142,136,1,0,0,0,142,137,1,0,
  	0,0,143,19,1,0,0,0,144,151,5,3,0,0,145,146,3,24,12,0,146,147,5,22,0,0,
  	147,148,5,3,0,0,148,151,1,0,0,0,149,151,3,26,13,0,150,144,1,0,0,0,150,
  	145,1,0,0,0,150,149,1,0,0,0,151,21,1,0,0,0,152,153,3,30,15,0,153,23,1,
  	0,0,0,154,155,3,30,15,0,155,25,1,0,0,0,156,157,3,30,15,0,157,27,1,0,0,
  	0,158,159,3,30,15,0,159,29,1,0,0,0,160,168,5,38,0,0,161,168,5,39,0,0,
  	162,168,5,40,0,0,163,164,5,19,0,0,164,165,3,30,15,0,165,166,5,20,0,0,
  	166,168,1,0,0,0,167,160,1,0,0,0,167,161,1,0,0,0,167,162,1,0,0,0,167,163,
  	1,0,0,0,168,31,1,0,0,0,15,36,41,47,54,60,68,75,90,95,118,120,128,142,
  	150,167
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mysqlParserStaticData = staticData.release();
}

}

mysqlParser::mysqlParser(TokenStream *input) : mysqlParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

mysqlParser::mysqlParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  mysqlParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mysqlParserStaticData->atn, mysqlParserStaticData->decisionToDFA, mysqlParserStaticData->sharedContextCache, options);
}

mysqlParser::~mysqlParser() {
  delete _interpreter;
}

const atn::ATN& mysqlParser::getATN() const {
  return *mysqlParserStaticData->atn;
}

std::string mysqlParser::getGrammarFileName() const {
  return "mysql.g4";
}

const std::vector<std::string>& mysqlParser::getRuleNames() const {
  return mysqlParserStaticData->ruleNames;
}

const dfa::Vocabulary& mysqlParser::getVocabulary() const {
  return mysqlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView mysqlParser::getSerializedATN() const {
  return mysqlParserStaticData->serializedATN;
}


//----------------- Sql_stmt_listContext ------------------------------------------------------------------

mysqlParser::Sql_stmt_listContext::Sql_stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<mysqlParser::Sql_stmtContext *> mysqlParser::Sql_stmt_listContext::sql_stmt() {
  return getRuleContexts<mysqlParser::Sql_stmtContext>();
}

mysqlParser::Sql_stmtContext* mysqlParser::Sql_stmt_listContext::sql_stmt(size_t i) {
  return getRuleContext<mysqlParser::Sql_stmtContext>(i);
}

tree::TerminalNode* mysqlParser::Sql_stmt_listContext::EOF() {
  return getToken(mysqlParser::EOF, 0);
}


size_t mysqlParser::Sql_stmt_listContext::getRuleIndex() const {
  return mysqlParser::RuleSql_stmt_list;
}


std::any mysqlParser::Sql_stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitSql_stmt_list(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Sql_stmt_listContext* mysqlParser::sql_stmt_list() {
  Sql_stmt_listContext *_localctx = _tracker.createInstance<Sql_stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 0, mysqlParser::RuleSql_stmt_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(32);
    sql_stmt();
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(34); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(33);
          match(mysqlParser::T__0);
          setState(36); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == mysqlParser::T__0);
        setState(38);
        sql_stmt(); 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == mysqlParser::T__0) {
      setState(44);
      match(mysqlParser::T__0);
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    match(mysqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmtContext ------------------------------------------------------------------

mysqlParser::Sql_stmtContext::Sql_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Select_stmtContext* mysqlParser::Sql_stmtContext::select_stmt() {
  return getRuleContext<mysqlParser::Select_stmtContext>(0);
}

mysqlParser::Use_stmtContext* mysqlParser::Sql_stmtContext::use_stmt() {
  return getRuleContext<mysqlParser::Use_stmtContext>(0);
}


size_t mysqlParser::Sql_stmtContext::getRuleIndex() const {
  return mysqlParser::RuleSql_stmt;
}


std::any mysqlParser::Sql_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitSql_stmt(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Sql_stmtContext* mysqlParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 2, mysqlParser::RuleSql_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case mysqlParser::SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        select_stmt();
        break;
      }

      case mysqlParser::USE: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        use_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Use_stmtContext ------------------------------------------------------------------

mysqlParser::Use_stmtContext::Use_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Use_stmtContext::USE() {
  return getToken(mysqlParser::USE, 0);
}

tree::TerminalNode* mysqlParser::Use_stmtContext::SECURE() {
  return getToken(mysqlParser::SECURE, 0);
}

tree::TerminalNode* mysqlParser::Use_stmtContext::INSECURE() {
  return getToken(mysqlParser::INSECURE, 0);
}


size_t mysqlParser::Use_stmtContext::getRuleIndex() const {
  return mysqlParser::RuleUse_stmt;
}


std::any mysqlParser::Use_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitUse_stmt(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Use_stmtContext* mysqlParser::use_stmt() {
  Use_stmtContext *_localctx = _tracker.createInstance<Use_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, mysqlParser::RuleUse_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(60);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(56);
      match(mysqlParser::USE);
      setState(57);
      match(mysqlParser::SECURE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(58);
      match(mysqlParser::USE);
      setState(59);
      match(mysqlParser::INSECURE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

mysqlParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Select_stmtContext::SELECT() {
  return getToken(mysqlParser::SELECT, 0);
}

std::vector<mysqlParser::ResultContext *> mysqlParser::Select_stmtContext::result() {
  return getRuleContexts<mysqlParser::ResultContext>();
}

mysqlParser::ResultContext* mysqlParser::Select_stmtContext::result(size_t i) {
  return getRuleContext<mysqlParser::ResultContext>(i);
}

tree::TerminalNode* mysqlParser::Select_stmtContext::FROM() {
  return getToken(mysqlParser::FROM, 0);
}

mysqlParser::Table_nameContext* mysqlParser::Select_stmtContext::table_name() {
  return getRuleContext<mysqlParser::Table_nameContext>(0);
}

tree::TerminalNode* mysqlParser::Select_stmtContext::WHERE() {
  return getToken(mysqlParser::WHERE, 0);
}

mysqlParser::ExprContext* mysqlParser::Select_stmtContext::expr() {
  return getRuleContext<mysqlParser::ExprContext>(0);
}


size_t mysqlParser::Select_stmtContext::getRuleIndex() const {
  return mysqlParser::RuleSelect_stmt;
}


std::any mysqlParser::Select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitSelect_stmt(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Select_stmtContext* mysqlParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, mysqlParser::RuleSelect_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(mysqlParser::SELECT);
    setState(63);
    result();
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == mysqlParser::T__1) {
      setState(64);
      match(mysqlParser::T__1);
      setState(65);
      result();
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    match(mysqlParser::FROM);
    setState(72);
    table_name();
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == mysqlParser::WHERE) {
      setState(73);
      match(mysqlParser::WHERE);
      setState(74);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

mysqlParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Primary_exprContext* mysqlParser::ExprContext::primary_expr() {
  return getRuleContext<mysqlParser::Primary_exprContext>(0);
}

mysqlParser::Unary_operatorContext* mysqlParser::ExprContext::unary_operator() {
  return getRuleContext<mysqlParser::Unary_operatorContext>(0);
}

std::vector<mysqlParser::ExprContext *> mysqlParser::ExprContext::expr() {
  return getRuleContexts<mysqlParser::ExprContext>();
}

mysqlParser::ExprContext* mysqlParser::ExprContext::expr(size_t i) {
  return getRuleContext<mysqlParser::ExprContext>(i);
}

mysqlParser::Column_nameContext* mysqlParser::ExprContext::column_name() {
  return getRuleContext<mysqlParser::Column_nameContext>(0);
}

tree::TerminalNode* mysqlParser::ExprContext::IN() {
  return getToken(mysqlParser::IN, 0);
}

std::vector<mysqlParser::Column_valueContext *> mysqlParser::ExprContext::column_value() {
  return getRuleContexts<mysqlParser::Column_valueContext>();
}

mysqlParser::Column_valueContext* mysqlParser::ExprContext::column_value(size_t i) {
  return getRuleContext<mysqlParser::Column_valueContext>(i);
}

tree::TerminalNode* mysqlParser::ExprContext::AND() {
  return getToken(mysqlParser::AND, 0);
}

tree::TerminalNode* mysqlParser::ExprContext::OR() {
  return getToken(mysqlParser::OR, 0);
}


size_t mysqlParser::ExprContext::getRuleIndex() const {
  return mysqlParser::RuleExpr;
}


std::any mysqlParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


mysqlParser::ExprContext* mysqlParser::expr() {
   return expr(0);
}

mysqlParser::ExprContext* mysqlParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  mysqlParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  mysqlParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, mysqlParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(78);
      primary_expr();
      break;
    }

    case 2: {
      setState(79);
      unary_operator();
      setState(80);
      expr(9);
      break;
    }

    case 3: {
      setState(82);
      column_name();
      setState(83);
      match(mysqlParser::IN);
      setState(84);
      match(mysqlParser::T__18);
      setState(85);
      column_value();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == mysqlParser::T__1) {
        setState(86);
        match(mysqlParser::T__1);
        setState(87);
        column_value();
        setState(92);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(93);
      match(mysqlParser::T__19);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(120);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(118);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(97);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(98);
          antlrcpp::downCast<ExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 56) != 0)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(99);
          expr(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(100);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(101);
          antlrcpp::downCast<ExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == mysqlParser::T__5

          || _la == mysqlParser::T__6)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(102);
          expr(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(103);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(104);
          antlrcpp::downCast<ExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 3840) != 0)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(105);
          expr(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(106);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(107);
          antlrcpp::downCast<ExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 61440) != 0)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(108);
          expr(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(109);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(110);
          antlrcpp::downCast<ExprContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 458752) != 0)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(111);
          expr(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(113);
          match(mysqlParser::AND);
          setState(114);
          expr(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(115);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(116);
          match(mysqlParser::OR);
          setState(117);
          expr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(122);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Primary_exprContext ------------------------------------------------------------------

mysqlParser::Primary_exprContext::Primary_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Literal_valueContext* mysqlParser::Primary_exprContext::literal_value() {
  return getRuleContext<mysqlParser::Literal_valueContext>(0);
}

mysqlParser::ExprContext* mysqlParser::Primary_exprContext::expr() {
  return getRuleContext<mysqlParser::ExprContext>(0);
}


size_t mysqlParser::Primary_exprContext::getRuleIndex() const {
  return mysqlParser::RulePrimary_expr;
}


std::any mysqlParser::Primary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitPrimary_expr(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Primary_exprContext* mysqlParser::primary_expr() {
  Primary_exprContext *_localctx = _tracker.createInstance<Primary_exprContext>(_ctx, getState());
  enterRule(_localctx, 10, mysqlParser::RulePrimary_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case mysqlParser::IDENTIFIER:
      case mysqlParser::DECIMAL_LITERAL:
      case mysqlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(123);
        literal_value();
        break;
      }

      case mysqlParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(124);
        match(mysqlParser::T__18);
        setState(125);
        expr(0);
        setState(126);
        match(mysqlParser::T__19);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

mysqlParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Literal_valueContext::DECIMAL_LITERAL() {
  return getToken(mysqlParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* mysqlParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(mysqlParser::STRING_LITERAL, 0);
}

tree::TerminalNode* mysqlParser::Literal_valueContext::IDENTIFIER() {
  return getToken(mysqlParser::IDENTIFIER, 0);
}


size_t mysqlParser::Literal_valueContext::getRuleIndex() const {
  return mysqlParser::RuleLiteral_value;
}


std::any mysqlParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Literal_valueContext* mysqlParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 12, mysqlParser::RuleLiteral_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregate_funcContext ------------------------------------------------------------------

mysqlParser::Aggregate_funcContext::Aggregate_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Aggregate_funcContext::MIN() {
  return getToken(mysqlParser::MIN, 0);
}

tree::TerminalNode* mysqlParser::Aggregate_funcContext::MAX() {
  return getToken(mysqlParser::MAX, 0);
}

tree::TerminalNode* mysqlParser::Aggregate_funcContext::SUM() {
  return getToken(mysqlParser::SUM, 0);
}

tree::TerminalNode* mysqlParser::Aggregate_funcContext::AVG() {
  return getToken(mysqlParser::AVG, 0);
}

tree::TerminalNode* mysqlParser::Aggregate_funcContext::COUNT() {
  return getToken(mysqlParser::COUNT, 0);
}


size_t mysqlParser::Aggregate_funcContext::getRuleIndex() const {
  return mysqlParser::RuleAggregate_func;
}


std::any mysqlParser::Aggregate_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitAggregate_func(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Aggregate_funcContext* mysqlParser::aggregate_func() {
  Aggregate_funcContext *_localctx = _tracker.createInstance<Aggregate_funcContext>(_ctx, getState());
  enterRule(_localctx, 14, mysqlParser::RuleAggregate_func);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 266287972352) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

mysqlParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Unary_operatorContext::NOT() {
  return getToken(mysqlParser::NOT, 0);
}


size_t mysqlParser::Unary_operatorContext::getRuleIndex() const {
  return mysqlParser::RuleUnary_operator;
}


std::any mysqlParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Unary_operatorContext* mysqlParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 16, mysqlParser::RuleUnary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538968256) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResultContext ------------------------------------------------------------------

mysqlParser::ResultContext::ResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Result_columnContext* mysqlParser::ResultContext::result_column() {
  return getRuleContext<mysqlParser::Result_columnContext>(0);
}

mysqlParser::Aggregate_funcContext* mysqlParser::ResultContext::aggregate_func() {
  return getRuleContext<mysqlParser::Aggregate_funcContext>(0);
}


size_t mysqlParser::ResultContext::getRuleIndex() const {
  return mysqlParser::RuleResult;
}


std::any mysqlParser::ResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitResult(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::ResultContext* mysqlParser::result() {
  ResultContext *_localctx = _tracker.createInstance<ResultContext>(_ctx, getState());
  enterRule(_localctx, 18, mysqlParser::RuleResult);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case mysqlParser::T__2:
      case mysqlParser::T__18:
      case mysqlParser::IDENTIFIER:
      case mysqlParser::DECIMAL_LITERAL:
      case mysqlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(136);
        result_column();
        break;
      }

      case mysqlParser::COUNT:
      case mysqlParser::MAX:
      case mysqlParser::MIN:
      case mysqlParser::SUM:
      case mysqlParser::AVG: {
        enterOuterAlt(_localctx, 2);
        setState(137);
        aggregate_func();
        setState(138);
        match(mysqlParser::T__18);
        setState(139);
        result_column();
        setState(140);
        match(mysqlParser::T__19);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

mysqlParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Table_nameContext* mysqlParser::Result_columnContext::table_name() {
  return getRuleContext<mysqlParser::Table_nameContext>(0);
}

mysqlParser::Column_nameContext* mysqlParser::Result_columnContext::column_name() {
  return getRuleContext<mysqlParser::Column_nameContext>(0);
}


size_t mysqlParser::Result_columnContext::getRuleIndex() const {
  return mysqlParser::RuleResult_column;
}


std::any mysqlParser::Result_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitResult_column(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Result_columnContext* mysqlParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 20, mysqlParser::RuleResult_column);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      match(mysqlParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      table_name();
      setState(146);
      match(mysqlParser::T__21);
      setState(147);
      match(mysqlParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(149);
      column_name();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Schema_nameContext ------------------------------------------------------------------

mysqlParser::Schema_nameContext::Schema_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Any_nameContext* mysqlParser::Schema_nameContext::any_name() {
  return getRuleContext<mysqlParser::Any_nameContext>(0);
}


size_t mysqlParser::Schema_nameContext::getRuleIndex() const {
  return mysqlParser::RuleSchema_name;
}


std::any mysqlParser::Schema_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitSchema_name(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Schema_nameContext* mysqlParser::schema_name() {
  Schema_nameContext *_localctx = _tracker.createInstance<Schema_nameContext>(_ctx, getState());
  enterRule(_localctx, 22, mysqlParser::RuleSchema_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

mysqlParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Any_nameContext* mysqlParser::Table_nameContext::any_name() {
  return getRuleContext<mysqlParser::Any_nameContext>(0);
}


size_t mysqlParser::Table_nameContext::getRuleIndex() const {
  return mysqlParser::RuleTable_name;
}


std::any mysqlParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Table_nameContext* mysqlParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 24, mysqlParser::RuleTable_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

mysqlParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Any_nameContext* mysqlParser::Column_nameContext::any_name() {
  return getRuleContext<mysqlParser::Any_nameContext>(0);
}


size_t mysqlParser::Column_nameContext::getRuleIndex() const {
  return mysqlParser::RuleColumn_name;
}


std::any mysqlParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitColumn_name(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Column_nameContext* mysqlParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 26, mysqlParser::RuleColumn_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_valueContext ------------------------------------------------------------------

mysqlParser::Column_valueContext::Column_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mysqlParser::Any_nameContext* mysqlParser::Column_valueContext::any_name() {
  return getRuleContext<mysqlParser::Any_nameContext>(0);
}


size_t mysqlParser::Column_valueContext::getRuleIndex() const {
  return mysqlParser::RuleColumn_value;
}


std::any mysqlParser::Column_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitColumn_value(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Column_valueContext* mysqlParser::column_value() {
  Column_valueContext *_localctx = _tracker.createInstance<Column_valueContext>(_ctx, getState());
  enterRule(_localctx, 28, mysqlParser::RuleColumn_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

mysqlParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mysqlParser::Any_nameContext::IDENTIFIER() {
  return getToken(mysqlParser::IDENTIFIER, 0);
}

tree::TerminalNode* mysqlParser::Any_nameContext::DECIMAL_LITERAL() {
  return getToken(mysqlParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* mysqlParser::Any_nameContext::STRING_LITERAL() {
  return getToken(mysqlParser::STRING_LITERAL, 0);
}

mysqlParser::Any_nameContext* mysqlParser::Any_nameContext::any_name() {
  return getRuleContext<mysqlParser::Any_nameContext>(0);
}


size_t mysqlParser::Any_nameContext::getRuleIndex() const {
  return mysqlParser::RuleAny_name;
}


std::any mysqlParser::Any_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mysqlVisitor*>(visitor))
    return parserVisitor->visitAny_name(this);
  else
    return visitor->visitChildren(this);
}

mysqlParser::Any_nameContext* mysqlParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 30, mysqlParser::RuleAny_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case mysqlParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        match(mysqlParser::IDENTIFIER);
        break;
      }

      case mysqlParser::DECIMAL_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(161);
        match(mysqlParser::DECIMAL_LITERAL);
        break;
      }

      case mysqlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(162);
        match(mysqlParser::STRING_LITERAL);
        break;
      }

      case mysqlParser::T__18: {
        enterOuterAlt(_localctx, 4);
        setState(163);
        match(mysqlParser::T__18);
        setState(164);
        any_name();
        setState(165);
        match(mysqlParser::T__19);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool mysqlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool mysqlParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void mysqlParser::initialize() {
  ::antlr4::internal::call_once(mysqlParserOnceFlag, mysqlParserInitialize);
}
