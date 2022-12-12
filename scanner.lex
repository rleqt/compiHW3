%{

/* Declarations section */
    #include <stdio.h>
    #include "yysType.hpp"
    #include "parser.tab.hpp"
    #include "hw3_output.hpp"
    #include "symbolTable.hpp"
    #include <stdlib.h>
    using namespace std;
    using namespace output;

%}
%option yylineno
%option noyywrap

%%


void	return VOID;
int					return INT;
byte                return BYTE;
b                   return B;
bool                return BOOL;
and                 return AND;
or                  return OR;
not                 return NOT;
true                return TRUE;
false               return FALSE;
return              return RETURN;
if                  return IF;
else                return ELSE;
while				return WHILE;
break               return BREAK;
continue            return CONTINUE;
;                   return SC;
,                   return COMMA;
\(                  return LPAREN;
\)                  return RPAREN;
\{                  return LBRACE;
\}                  return RBRACE;
=                   return ASSIGN;

\<=                 return RELOP;
==                  return EQRELOP;
>=                  return RELOP;
>                   return RELOP;
\<                  return RELOP;
\!=                 return EQRELOP;

\*                  return MULTBINOP;
\/                  return MULTBINOP;
\+                  return BINOP;
-                   return BINOP;

[a-zA-Z][a-zA-Z0-9]*       { yylval.str=new std::string(yytext);  return ID;}
0|[1-9][0-9]*              { yylval.integer=new int(stoi(yytext));  return NUM;}
[\t\n\r ]   {};
\"([^\n\r\"\\]|\\[rnt\"\\])+\"	{ yylval.str=new std::string(yytext);  return STRING;}
\/\/[^\r\n]*[\r|\n|\r\n]?         {};

. {errorLex(yylineno); exit(1);}


%%

