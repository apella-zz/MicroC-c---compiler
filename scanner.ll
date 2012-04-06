/* $Id: scanner.ll 44 2008-10-23 09:03:19Z tb $ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include <iostream>
#include <vector>
#include "scanner.h"
/* import the parser's token type into a local typedef */
typedef example::Parser::token token;
typedef example::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ExampleFlexLexer" */
%option prefix="Example"

/* the manual says "somewhat more optimized" */
/* %option batch */

/* enable scanner to generate debug output. disable this for release
 * versions. */
/* %option debug */

/* no support for include files is planned */
/* %option yywrap nounput  */

/* enables the use of start condition stacks */
/* %option stack */

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}
alpha			[A-Za-z]
digit			[0-9]
alphanum		[A-Za-z0-9]

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/
[ \t\r]			break;		/* ignore white space */

int			{printf("an int!\n"); return token::INT;};	/* Keywords come before NAMEs */
if			return token::IF;
else			return token::ELSE;
return			return token::RETURN;
float			return token::FLOAT;
struct			return token::STRUCT;
read                    return token::READ;
write                   return token::WRITE;
length                  return token::LENGTH;
while                   return token::WHILE;
{alpha}{alphanum}*	{
                          yylval->name = yytext;
			  return token::NAME;
			}

{digit}+		{
			yylval->value	= atoi(yytext);
			return token::NUMBER;
			}

"("			return token::LPAR;
")"			return token::RPAR;
"{"			return token::LBRACE;
"}"			return token::RBRACE;
"["			return token::LBRACK;
"]"			return token::RBRACK;
"=="			return token::EQUAL;
"="			return token::ASSIGN;
"<"                     return token::LESS;
">"                     return token::GREATER;
"!"                     return token::NOT;
"!="                	return token::NEQUAL;
";"			return token::SEMICOLON;
","			return token::COMMA;
"."			return token::DOT;
"+"			return token::PLUS;
"-"			return token::MINUS;
"*"			return token::TIMES;
"/"			return token::DIVIDE;
.			{
			/*fprintf(stderr,
				"Illegal character with code %d on line #%d\n",
				*yytext, lineno);*/
			exit(1);
			}

 /*** END EXAMPLE - Change the example lexer rules above ***/

%% /*** Additional Code ***/

namespace example {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : ExampleFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ExampleFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ExampleFlexLexer::yywrap()
{
    return 1;
}
