/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "Node.h"
using std::vector;
%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start program

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="example"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
  int value;
  char character;
  class NProgram *program;
  class NDeclaration *decl;
  class NVar_declaration *var_declaration;
  class NFun_declaration *fun_declaration;
  class NBlock *block;
  class NStatement *statement;
  class NType *type;
  class NLeft_expression *lexp;
  class NExpression *exp;
  class NVar *var;
  std::vector<NExpression *>  *exprvec;
  std::vector<NVar_declaration*>*  varvec;
  std::vector<NStatement *>  *statvec;
  int token;
  char *name;
}

/* the tokens */
%token <name> NUMBER NAME
%token <character> QCHAR
%token <token> INT IF ELSE RETURN FLOAT STRUCT LPAR RPAR LBRACE RBRACE LESS LENGTH GREATER NOT NEQUAL END
%token <token> LBRACK RBRACK EQUAL ASSIGN SEMICOLON COMMA DOT PLUS MINUS TIMES DIVIDE WHILE WRITE READ

 /* type declarations of non-terminal symbols*/ 
%type <value> unop binop
%type <program> declarations
%type <var_declaration> var_declaration formal_par
%type <fun_declaration> fun_declaration
%type <block> block
%type <statement> statement
%type <type> type
%type <lexp> lexp
%type <exp> exp
%type <exprvec> pars
%type <varvec> formal_pars var_declarations
%type <statvec> statements
%type <var> var

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/

program		: declarations { driver.programBlock = $1; }
		;

declarations	: declaration { $$ = new NProgram(); $$->declarations->push_back($<decl>1); }
		| declarations declaration { $1->declarations->push_back($<decl>2); }
		;

declaration	: fun_declaration
		| var_declaration
		;

fun_declaration	: type NAME LPAR formal_pars RPAR block 
		{ $$ = new NFun_declaration($1, $2, $4, $6); }
		;

formal_pars	: /* empty */ { $$ = new VariableList(); }
		| formal_par  { $$ = new VariableList(); $$->push_back($1); }
		| formal_pars COMMA formal_par { $1->push_back($3); }
		;

formal_par	: type NAME { $$ = new NVar_declaration($1, $2); }
		;

block		: LBRACE var_declarations statements RBRACE {$$ = new NBlock($2, $3); }
		;

var_declarations: /* empty */ { $$ = new VariableList(); }
		| var_declaration { $$ = new VariableList(); $$->push_back($1); }
		| var_declarations var_declaration { $1->push_back($2); }
		;

var_declaration	: type NAME SEMICOLON { $$ = new NVar_declaration($1, $2); }
		;

type		: INT { $$ = new NType_int(); }
		| QCHAR { $$ = new NType_char(); }
		| type LBRACK exp RBRACK // array type
			{ $$ = new NType_array($1, $3); }
		;

statements	: /* empty */ { $$ = new StatementList(); }
		| statement { $$ = new StatementList(); $$->push_back($1); }
		| statements SEMICOLON statement { $1->push_back($3); }
		;

statement	: IF LPAR exp RPAR statement { $$ = new NStatement_if($3, $5); }
		| IF LPAR exp RPAR statement ELSE statement { $$ = new NStatement_if_double($3, $5, $7); }
		| WHILE LPAR exp RPAR statement { $$ = new NStatement_while($3, $5); }
		| lexp ASSIGN exp { $$ = new NStatement_assign($1, $3); }
		| RETURN exp { $$ = new NStatement_return($2); }
		| NAME LPAR pars RPAR /* function call */ { $$ = new NFunction_call($1, $3); }
		| block {$$ = $<block>1; }
		| WRITE exp { $$ = new NStatement_write($2); }
		| READ lexp { $$ = new NStatement_read($2); }
		;

lexp		: var { $$ = $<lexp>1; }
		| lexp LBRACK exp RBRACK { $$ = new NArray_access($1, $3); }	// array access
		;

exp		: lexp {$$ = $<exp>1; } 
		| exp binop exp { $$ = new NBinary_op($1, $3, $2); }
		| unop exp { $$ = new NUnary_op($2, $1); }
		| LPAR exp RPAR { $$ = $2; }
                | NUMBER { $$ = new NNumber(atol($1)); delete $1; }
		| NAME LPAR pars RPAR { $$ = new NFunction_call($1, $3); } // function call
/*| QCHAR { $$ = new NQchar($1); } */
		| LENGTH lexp { $$ = new NLength($<lexp>2); } // size of an array
		;

binop		: MINUS		{ $$ = 0; }
		| PLUS 		{ $$ = 1; }
		| TIMES		{ $$ = 2; }
		| DIVIDE	{ $$ = 3; }
		| EQUAL		{ $$ = 4; }
		| NEQUAL	{ $$ = 5; }
		| GREATER	{ $$ = 6; }
		| LESS		{ $$ = 7; }
		;

unop		: MINUS		{ $$ = 0; }
		| NOT		{ $$ = 1; }
		;

pars		: /* empty */ { $$ = new ExpressionList(); }
		| exp { $$ = new ExpressionList(); $$->push_back($<exp>1); }
		| pars COMMA exp { $1->push_back($<exp>3); }
		;

var		: NAME { $$ = new NVar($1); } 

 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
