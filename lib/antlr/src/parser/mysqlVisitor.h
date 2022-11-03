
// Generated from ./src/parser/mysql.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "mysqlParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by mysqlParser.
 */
class  mysqlVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by mysqlParser.
   */
    virtual std::any visitSql_stmt_list(mysqlParser::Sql_stmt_listContext *context) = 0;

    virtual std::any visitSql_stmt(mysqlParser::Sql_stmtContext *context) = 0;

    virtual std::any visitUse_stmt(mysqlParser::Use_stmtContext *context) = 0;

    virtual std::any visitSelect_stmt(mysqlParser::Select_stmtContext *context) = 0;

    virtual std::any visitExpr(mysqlParser::ExprContext *context) = 0;

    virtual std::any visitPrimary_expr(mysqlParser::Primary_exprContext *context) = 0;

    virtual std::any visitLiteral_value(mysqlParser::Literal_valueContext *context) = 0;

    virtual std::any visitAggregate_func(mysqlParser::Aggregate_funcContext *context) = 0;

    virtual std::any visitUnary_operator(mysqlParser::Unary_operatorContext *context) = 0;

    virtual std::any visitResult(mysqlParser::ResultContext *context) = 0;

    virtual std::any visitResult_column(mysqlParser::Result_columnContext *context) = 0;

    virtual std::any visitSchema_name(mysqlParser::Schema_nameContext *context) = 0;

    virtual std::any visitTable_name(mysqlParser::Table_nameContext *context) = 0;

    virtual std::any visitColumn_name(mysqlParser::Column_nameContext *context) = 0;

    virtual std::any visitColumn_value(mysqlParser::Column_valueContext *context) = 0;

    virtual std::any visitAny_name(mysqlParser::Any_nameContext *context) = 0;


};

