%{

/* Declarations section */
    #include <stdio.h>
    #include "parser.tab.hpp"
    #include "hw3_output.hpp"
    #include "yysType.hpp"
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

[a-zA-Z][a-zA-Z0-9]*       /* yylval.s=yytext;*/  return ID;
0|[1-9][0-9]*              /*yylval.intVal=atoi(yytext);*/ return NUM;
[\t\n\r ]   {};
\"([^\n\r\"\\]|\\[rnt\"\\])+\"	return STRING;
\/\/[^\r\n]*[\r|\n|\r\n]?         {};

. {errorLex(yylineno); exit(1);}


%%

