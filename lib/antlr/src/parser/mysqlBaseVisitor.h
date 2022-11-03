
// Generated from ./src/parser/mysql.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "mysqlVisitor.h"


/**
 * This class provides an empty implementation of mysqlVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  mysqlBaseVisitor : public mysqlVisitor {
public:

  virtual std::any visitSql_stmt_list(mysqlParser::Sql_stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSql_stmt(mysqlParser::Sql_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUse_stmt(mysqlParser::Use_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelect_stmt(mysqlParser::Select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(mysqlParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary_expr(mysqlParser::Primary_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral_value(mysqlParser::Literal_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAggregate_func(mysqlParser::Aggregate_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_operator(mysqlParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResult(mysqlParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResult_column(mysqlParser::Result_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSchema_name(mysqlParser::Schema_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTable_name(mysqlParser::Table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_name(mysqlParser::Column_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_value(mysqlParser::Column_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAny_name(mysqlParser::Any_nameContext *ctx) override {
    return visitChildren(ctx);
  }


};

