
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   examplelex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 4 "parser.yy"
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "Node.h"
using std::vector;


/* Line 311 of lalr1.cc  */
#line 54 "parser.cc"


#include "parser.h"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 99 "parser.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 77 "parser.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace example {

/* Line 380 of lalr1.cc  */
#line 146 "parser.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 41 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 330 "parser.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 116 "parser.yy"
    { driver.programBlock = (yysemantic_stack_[(1) - (1)].program); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 119 "parser.yy"
    { (yyval.program) = new NProgram(); (yyval.program)->declarations->push_back((yysemantic_stack_[(1) - (1)].decl)); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 120 "parser.yy"
    { (yysemantic_stack_[(2) - (1)].program)->declarations->push_back((yysemantic_stack_[(2) - (2)].decl)); }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 128 "parser.yy"
    { (yyval.fun_declaration) = new NFun_declaration((yysemantic_stack_[(6) - (1)].type), (yysemantic_stack_[(6) - (2)].name), (yysemantic_stack_[(6) - (4)].varvec), (yysemantic_stack_[(6) - (6)].block)); }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 131 "parser.yy"
    { (yyval.varvec) = new VariableList(); }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 132 "parser.yy"
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yysemantic_stack_[(1) - (1)].var_declaration)); }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 133 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].varvec)->push_back((yysemantic_stack_[(3) - (3)].var_declaration)); }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 136 "parser.yy"
    { (yyval.var_declaration) = new NVar_declaration((yysemantic_stack_[(2) - (1)].type), (yysemantic_stack_[(2) - (2)].name)); }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 139 "parser.yy"
    {(yyval.block) = new NBlock((yysemantic_stack_[(4) - (2)].varvec), (yysemantic_stack_[(4) - (3)].statvec)); }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 142 "parser.yy"
    { (yyval.varvec) = new VariableList(); }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 143 "parser.yy"
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yysemantic_stack_[(1) - (1)].var_declaration)); }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 144 "parser.yy"
    { (yysemantic_stack_[(2) - (1)].varvec)->push_back((yysemantic_stack_[(2) - (2)].var_declaration)); }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 147 "parser.yy"
    { (yyval.var_declaration) = new NVar_declaration((yysemantic_stack_[(3) - (1)].type), (yysemantic_stack_[(3) - (2)].name)); }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 150 "parser.yy"
    { (yyval.type) = new NType_int(); }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 151 "parser.yy"
    { (yyval.type) = new NType_char(); }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 153 "parser.yy"
    { (yyval.type) = new NType_array((yysemantic_stack_[(4) - (1)].type), (yysemantic_stack_[(4) - (3)].exp)); }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 156 "parser.yy"
    { (yyval.statvec) = new StatementList(); }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 157 "parser.yy"
    { (yyval.statvec) = new StatementList(); (yyval.statvec)->push_back((yysemantic_stack_[(1) - (1)].statement)); }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 158 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].statvec)->push_back((yysemantic_stack_[(3) - (3)].statement)); }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 161 "parser.yy"
    { (yyval.statement) = new NStatement_if((yysemantic_stack_[(5) - (3)].exp), (yysemantic_stack_[(5) - (5)].statement)); }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 162 "parser.yy"
    { (yyval.statement) = new NStatement_if_double((yysemantic_stack_[(7) - (3)].exp), (yysemantic_stack_[(7) - (5)].statement), (yysemantic_stack_[(7) - (7)].statement)); }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 163 "parser.yy"
    { (yyval.statement) = new NStatement_while((yysemantic_stack_[(5) - (3)].exp), (yysemantic_stack_[(5) - (5)].statement)); }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 164 "parser.yy"
    { (yyval.statement) = new NStatement_assign((yysemantic_stack_[(3) - (1)].lexp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 165 "parser.yy"
    { (yyval.statement) = new NStatement_return((yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 166 "parser.yy"
    { (yyval.statement) = new NFunction_call((yysemantic_stack_[(4) - (1)].name), (yysemantic_stack_[(4) - (3)].exprvec)); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 167 "parser.yy"
    {(yyval.statement) = (yysemantic_stack_[(1) - (1)].block); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 168 "parser.yy"
    { (yyval.statement) = new NStatement_write((yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 169 "parser.yy"
    { (yyval.statement) = new NStatement_read((yysemantic_stack_[(2) - (2)].lexp)); }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 172 "parser.yy"
    { (yyval.lexp) = (yysemantic_stack_[(1) - (1)].lexp); }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 173 "parser.yy"
    { (yyval.lexp) = new NArray_access((yysemantic_stack_[(4) - (1)].lexp), (yysemantic_stack_[(4) - (3)].exp)); }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 176 "parser.yy"
    {(yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 177 "parser.yy"
    { (yyval.exp) = new NBinary_op((yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp), (yysemantic_stack_[(3) - (2)].value)); }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 178 "parser.yy"
    { (yyval.exp) = new NUnary_op((yysemantic_stack_[(2) - (2)].exp), (yysemantic_stack_[(2) - (1)].value)); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 179 "parser.yy"
    { (yyval.exp) = (yysemantic_stack_[(3) - (2)].exp); }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 180 "parser.yy"
    { (yyval.exp) = new NNumber(atol((yysemantic_stack_[(1) - (1)].name))); delete (yysemantic_stack_[(1) - (1)].name); }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 181 "parser.yy"
    { (yyval.exp) = new NFunction_call((yysemantic_stack_[(4) - (1)].name), (yysemantic_stack_[(4) - (3)].exprvec)); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 183 "parser.yy"
    { (yyval.exp) = new NLength((yysemantic_stack_[(2) - (2)].lexp)); }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 186 "parser.yy"
    { (yyval.value) = 0; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 187 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 188 "parser.yy"
    { (yyval.value) = 2; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 189 "parser.yy"
    { (yyval.value) = 3; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 190 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 191 "parser.yy"
    { (yyval.value) = 5; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 192 "parser.yy"
    { (yyval.value) = 6; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 193 "parser.yy"
    { (yyval.value) = 7; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 196 "parser.yy"
    { (yyval.value) = 0; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 197 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 200 "parser.yy"
    { (yyval.exprvec) = new ExpressionList(); }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 201 "parser.yy"
    { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yysemantic_stack_[(1) - (1)].exp)); }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 202 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].exprvec)->push_back((yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 205 "parser.yy"
    { (yyval.var) = new NVar((yysemantic_stack_[(1) - (1)].name)); }
    break;



/* Line 678 of lalr1.cc  */
#line 806 "parser.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -49;
  const short int
  Parser::yypact_[] =
  {
        40,   -49,   -49,     9,    40,   -49,   -49,   -49,    -3,   -49,
     -49,    -5,    50,    40,   -49,   -49,    -1,    50,    12,   -49,
     -49,    -4,   118,    50,   -49,     0,   -49,    -2,    50,    61,
     -49,    -4,    50,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,    50,   152,    34,    40,   -49,   152,    38,   -49,
     135,   152,    40,   -49,   -49,   -49,    50,   -49,    25,   -49,
       2,   152,    16,    49,    50,    52,    50,    12,   -49,   -49,
      10,   -49,    13,    26,    50,    50,   152,    50,   152,    -4,
     -49,     8,    50,    43,    81,   101,   -49,   152,   -49,     8,
       8,    18,   -49,     8,   -49
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,    18,    17,     0,     2,     3,     5,     6,     0,     1,
       4,     0,     0,     8,    16,    38,    54,     0,     0,    50,
      49,    34,     0,     0,    32,     0,     9,     0,    51,     0,
      54,    40,     0,    48,    47,    46,    19,    45,    42,    41,
      43,    44,     0,    36,     0,     0,    11,    52,     0,    37,
       0,    35,    13,     7,    10,    39,     0,    33,    20,    14,
       0,    53,    54,     0,     0,     0,     0,     0,    29,    15,
       0,    21,     0,     0,    51,     0,    27,     0,    30,    31,
      12,     0,     0,     0,     0,     0,    22,    26,    28,     0,
       0,    23,    25,     0,    24
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -49,   -49,   -49,    72,   -49,   -49,    33,    39,   -49,   -48,
      -8,   -49,    14,   -18,    -9,   -49,   -49,    15,   -49
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     3,     4,     5,     6,    25,    26,    68,    58,     7,
       8,    70,    71,    21,    47,    42,    23,    48,    24
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        31,    11,    46,    22,    59,    27,    73,    13,    29,     9,
      69,    28,    62,    44,    43,    63,    30,    64,    32,    12,
      12,    14,    52,    50,    12,    80,    93,    45,    74,    62,
       1,     2,    63,    51,    64,    32,    81,    27,    82,    52,
      72,    65,    66,    67,    60,     1,     2,    61,    52,    79,
      60,    55,    14,    15,    16,    76,    88,    78,    65,    66,
      67,    75,    17,    72,    77,    56,    84,    18,    85,    19,
      56,    72,    72,    87,    49,    72,    10,    33,    54,    34,
      20,    35,     0,    53,     0,    37,     0,     0,     0,    83,
      38,    39,    40,    41,    89,    86,     0,    33,     0,    34,
       0,    35,     0,    91,    92,    37,     0,    94,     0,     0,
      38,    39,    40,    41,    90,     0,     0,    33,     0,    34,
       0,    35,     0,     0,     0,    37,     0,     0,     0,     0,
      38,    39,    40,    41,    33,     0,    34,     0,    35,     0,
       0,    36,    37,     0,     0,     0,     0,    38,    39,    40,
      41,    33,     0,    34,     0,    35,     0,     0,    57,    37,
       0,     0,     0,     0,    38,    39,    40,    41,    33,     0,
      34,     0,    35,     0,     0,     0,    37,     0,     0,     0,
       0,    38,    39,    40,    41
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        18,     4,     4,    12,    52,    13,     4,    12,    17,     0,
      58,    12,     4,    13,    23,     7,     4,     9,    22,    22,
      22,    26,    14,    32,    22,    15,     8,    27,    12,     4,
       5,     6,     7,    42,     9,    22,    26,    45,    25,    14,
      58,    33,    34,    35,    52,     5,     6,    56,    14,    67,
      58,    13,    26,     3,     4,    64,    13,    66,    33,    34,
      35,    12,    12,    81,    12,    27,    75,    17,    77,    19,
      27,    89,    90,    82,    13,    93,     4,    16,    45,    18,
      30,    20,    -1,    44,    -1,    24,    -1,    -1,    -1,    74,
      29,    30,    31,    32,    13,    81,    -1,    16,    -1,    18,
      -1,    20,    -1,    89,    90,    24,    -1,    93,    -1,    -1,
      29,    30,    31,    32,    13,    -1,    -1,    16,    -1,    18,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    16,    -1,    18,    -1,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    16,    -1,
      18,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     5,     6,    37,    38,    39,    40,    45,    46,     0,
      39,     4,    22,    12,    26,     3,     4,    12,    17,    19,
      30,    49,    50,    52,    54,    41,    42,    46,    12,    50,
       4,    49,    22,    16,    18,    20,    23,    24,    29,    30,
      31,    32,    51,    50,    13,    27,     4,    50,    53,    13,
      50,    50,    14,    43,    42,    13,    27,    23,    44,    45,
      46,    50,     4,     7,     9,    33,    34,    35,    43,    45,
      47,    48,    49,     4,    12,    12,    50,    12,    50,    49,
      15,    26,    25,    53,    50,    50,    48,    50,    13,    13,
      13,    48,    48,     8,    48
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      41,    42,    43,    44,    44,    44,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    54
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     1,     2,     1,     1,     6,     0,     1,
       3,     2,     4,     0,     1,     2,     3,     1,     1,     4,
       0,     1,     3,     5,     7,     5,     3,     2,     4,     1,
       2,     2,     1,     4,     1,     3,     2,     3,     1,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMBER", "NAME", "QCHAR", "INT", "IF",
  "ELSE", "RETURN", "FLOAT", "STRUCT", "LPAR", "RPAR", "LBRACE", "RBRACE",
  "LESS", "LENGTH", "GREATER", "NOT", "NEQUAL", "END", "LBRACK", "RBRACK",
  "EQUAL", "ASSIGN", "SEMICOLON", "COMMA", "DOT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "WHILE", "WRITE", "READ", "$accept", "program", "declarations",
  "declaration", "fun_declaration", "formal_pars", "formal_par", "block",
  "var_declarations", "var_declaration", "type", "statements", "statement",
  "lexp", "exp", "binop", "unop", "pars", "var", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        37,     0,    -1,    38,    -1,    39,    -1,    38,    39,    -1,
      40,    -1,    45,    -1,    46,     4,    12,    41,    13,    43,
      -1,    -1,    42,    -1,    41,    27,    42,    -1,    46,     4,
      -1,    14,    44,    47,    15,    -1,    -1,    45,    -1,    44,
      45,    -1,    46,     4,    26,    -1,     6,    -1,     5,    -1,
      46,    22,    50,    23,    -1,    -1,    48,    -1,    47,    26,
      48,    -1,     7,    12,    50,    13,    48,    -1,     7,    12,
      50,    13,    48,     8,    48,    -1,    33,    12,    50,    13,
      48,    -1,    49,    25,    50,    -1,     9,    50,    -1,     4,
      12,    53,    13,    -1,    43,    -1,    34,    50,    -1,    35,
      49,    -1,    54,    -1,    49,    22,    50,    23,    -1,    49,
      -1,    50,    51,    50,    -1,    52,    50,    -1,    12,    50,
      13,    -1,     3,    -1,     4,    12,    53,    13,    -1,    17,
      49,    -1,    30,    -1,    29,    -1,    31,    -1,    32,    -1,
      24,    -1,    20,    -1,    18,    -1,    16,    -1,    30,    -1,
      19,    -1,    -1,    50,    -1,    53,    27,    50,    -1,     4,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    10,    12,    14,    21,    22,
      24,    28,    31,    36,    37,    39,    42,    46,    48,    50,
      55,    56,    58,    62,    68,    76,    82,    86,    89,    94,
      96,    99,   102,   104,   109,   111,   115,   118,   122,   124,
     129,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   152,   153,   155,   159
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   116,   116,   119,   120,   123,   124,   127,   131,   132,
     133,   136,   139,   142,   143,   144,   147,   150,   151,   152,
     156,   157,   158,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   172,   173,   176,   177,   178,   179,   180,   181,
     183,   186,   187,   188,   189,   190,   191,   192,   193,   196,
     197,   200,   201,   202,   205
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 184;
  const int Parser::yynnts_ = 19;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 9;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 36;

  const unsigned int Parser::yyuser_token_number_max_ = 290;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // example

/* Line 1054 of lalr1.cc  */
#line 1327 "parser.cc"


/* Line 1056 of lalr1.cc  */
#line 209 "parser.yy"
 /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

