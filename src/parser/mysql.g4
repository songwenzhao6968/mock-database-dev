grammar mysql;

IN: 'IN';
SELECT: 'SELECT';
FROM: 'FROM';
WHERE: 'WHERE';
AND: 'and' | 'AND';
OR: 'or' | 'OR';
NOT: 'not';
USE: 'USE';
SECURE: 'SECURE';
INSECURE: 'INSECURE';
COUNT: 'COUNT';
MAX: 'MAX';
MIN: 'MIN';
SUM: 'SUM';
AVG: 'AVG';



IDENTIFIER
    : [a-zA-Z_] [a-zA-Z_0-9]*
    ;

DECIMAL_LITERAL
    : [1-9] [0-9]*
    | '0'
    ;
STRING_LITERAL:     '"' (~["\\\r\n]| '\\' ["n\\])* '"';

SINGLE_LINE_COMMENT:
	'--' ~[\r\n]* (('\r'? '\n') | EOF) -> channel(HIDDEN);

MULTILINE_COMMENT: '/*' .*? ( '*/' | EOF) -> channel(HIDDEN);

SPACES: [ \u000B\t\r\n] -> channel(HIDDEN);

sql_stmt_list: sql_stmt (';'+ sql_stmt)* ';'* EOF;

sql_stmt:
    select_stmt
    | use_stmt
    ;

use_stmt:
    USE SECURE
    | USE INSECURE
    ;

select_stmt:
    SELECT  result (
    			',' result
    		)*
    		FROM table_name
    		(WHERE expr)?
    ;

expr:
	primary_expr
	| unary_operator expr
	| expr bop=( '*' | '/' | '%') expr
	| expr bop=( '+' | '-') expr
	| expr bop=( '<<' | '>>' | '&' | '|') expr
	| expr bop=( '<' | '<=' | '>' | '>=') expr
	| expr bop=(
		'='
		| '=='
		| '!='
	) expr
	| expr AND expr
    | expr OR expr
    | column_name IN '(' column_value (',' column_value)* ')'
	; // IN op2

primary_expr:
    literal_value
    | '(' expr ')'
    ;

literal_value:
	DECIMAL_LITERAL
	| STRING_LITERAL
	| IDENTIFIER
	;

aggregate_func: MIN | MAX | SUM | AVG | COUNT;
unary_operator: '-' | '+' | '~' | NOT;
result:
    result_column
    | aggregate_func '(' result_column ')'
    ;

result_column:
	'*'
	| table_name '.' '*'
	| column_name;
schema_name: any_name;
table_name: any_name;
column_name: any_name;
column_value: any_name;

any_name: IDENTIFIER
    | DECIMAL_LITERAL
	| STRING_LITERAL
	| '(' any_name ')'
	;