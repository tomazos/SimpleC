/* simplec 1.0d1 - demonstration of compiler construction with yacc & lex

 Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>

 This software is available under the licensing terms set forth in the
 attached LICENSE file.
*/

%{
	#include "node.h"
	#define YYSTYPE node
	#include "parser.h"
	#include "symtable.h"
	#include "make_tree.h"
%}

ID		[a-zA-Z_][a-zA-Z0-9_]*
NUM		[0-9]+
WSPACE 	" "|"\t"|"\n"

%option noyywrap

%x	COMMENT

%%
	
"int"			return INT;
"scan"			return SCAN;
"print"			return PRINT;

{ID}			yylval = make_id(symtable::put_symbol(yytext)); return ID;
{NUM}			yylval = make_num(atoi(yytext)); return NUM;

";"				return SEMI;

"="				return EQUALS;
"+"				return PLUS;
"-"				return MINUS;
"*"				return MULT;
"/"				return DIV;
"("				return LPAREN;
")"				return RPAREN;

{WSPACE}		;

.				fprintf(stderr, "ERROR: Unrecognized character: %s\n", yytext); exit(1);

"//"			BEGIN(COMMENT);

<COMMENT>"\n"	BEGIN(INITIAL);
<COMMENT>.		;

%%
