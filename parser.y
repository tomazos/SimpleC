// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

%{
	#include "stdio.h"
	#include "make_tree.h"
	#include "node.h"
	
	#define YYSTYPE node
	
	void yyerror(const char*);

	int yylex();
%}

%token ID
%token NUM
%token SEMI
%token EQUALS
%token MINUS
%token PLUS
%token MULT
%token DIV
%token LPAREN
%token RPAREN
%token INT
%token SCAN
%token PRINT
%token INTO

%error-verbose

%%

CompilationUnit:
	| Statement { process_statement($1); } SEMI CompilationUnit

Statement:
	| LocalVarDecl { $$ = $1; }
	| Assignment { $$ = $1; }
	| PrintStmt { $$ = $1; }
	| ScanStmt { $$ = $1; }
	;

LocalVarDecl: Type ID 		{ $$ = make_local_var_decl($1, $2); };

Assignment: ID EQUALS Expr 	{ $$ = make_assignment($1, $3); };

PrintStmt:
	PRINT ID 				{ $$ = make_print_stmt($2); };

ScanStmt:
	SCAN ID 				{ $$ = make_scan_stmt($2); };

Expr:
	  ID 					{ $$ = $1; }
	| NUM 					{ $$ = $1; }
	| LPAREN Expr RPAREN 	{ $$ = $2; }
	| Expr PLUS Expr		{ $$ = make_plus_expr($1,$3); }
	| Expr MINUS Expr		{ $$ = make_minus_expr($1, $3); }
	| Expr MULT Expr		{ $$ = make_mult_expr($1, $3); }
	| Expr DIV Expr			{ $$ = make_div_expr($1, $3); }
	| MINUS Expr			{ $$ = make_negation($2); }
	;

Type: INT { $$ = make_type_int(); };

%%

void yyerror(const char* s)
{
	fprintf(stderr,"ERROR %s\n", s);
}
