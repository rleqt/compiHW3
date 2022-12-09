#ifndef TOKENS_HPP_
#define TOKENS_HPP_
enum tokentype {
	VOID_yy = 1,
	INT_yy = 2,
	BYTE_yy = 3,
	B_yy = 4,
	BOOL_yy = 5,
	AND_yy = 6,
	OR_yy = 7,
	NOT_yy = 8,
	TRUE_yy = 9,
	FALSE_yy = 10,
	RETURN_yy = 11,
	IF_yy = 12,
	ELSE_yy = 13,
	WHILE_yy = 14,
	BREAK_yy = 15,
	CONTINUE_yy = 16,
	SC_yy = 17,
	COMMA_yy = 18,
	LPAREN_yy = 19,
	RPAREN_yy = 20,
	LBRACE_yy = 21,
	RBRACE_yy = 22,
	ASSIGN_yy = 23,
	RELOP_yy = 24,
	BINOP_yy = 25,
	COMMENT_yy = 26,
	ID_yy = 27,
	NUM_yy = 28,
	STRING_yy = 29 ,
	ERROR_yy =30,
	WHITESPACE_yy = 31
    EQUAL =32,
    NOTEQUAL = 33,

};
extern int yylineno;
extern char* yytext;
extern int yyleng;
extern int yylex();
#endif /* TOKENS_HPP_ */