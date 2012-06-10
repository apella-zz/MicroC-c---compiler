/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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
#define yylex   miniClex

/* First part of user declarations.  */

/* Line 293 of lalr1.cc  */
#line 4 "parser.yy"
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "Node.h"
using std::vector;


/* Line 293 of lalr1.cc  */
#line 52 "parser.cc"


#include "parser.h"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 113 "parser.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 75 "parser.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace miniC {

/* Line 382 of lalr1.cc  */
#line 161 "parser.cc"

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

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 41 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 355 "parser.cc"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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

/* Line 690 of lalr1.cc  */
#line 130 "parser.yy"
    { driver.programBlock = (yysemantic_stack_[(1) - (1)].program); }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 141 "parser.yy"
    {(yyval.program) = new NProgram(); (yyval.program)->functions->push_back((yysemantic_stack_[(1) - (1)].fun_declaration)); }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 142 "parser.yy"
    { (yyval.program) = new NProgram(); (yyval.program)->variables->push_back((yysemantic_stack_[(1) - (1)].var_declaration)); }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 143 "parser.yy"
    {(yysemantic_stack_[(2) - (1)].program)->functions->push_back((yysemantic_stack_[(2) - (2)].fun_declaration)); }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 144 "parser.yy"
    {(yysemantic_stack_[(2) - (1)].program)->variables->push_back((yysemantic_stack_[(2) - (2)].var_declaration)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 145 "parser.yy"
    {(yyval.program) = new NProgram(); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 158 "parser.yy"
    { (yyval.fun_declaration) = new NFun_declaration((yysemantic_stack_[(6) - (1)].type), yylval.name, (yysemantic_stack_[(6) - (4)].varvec), (yysemantic_stack_[(6) - (6)].block)); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 162 "parser.yy"
    { (yyval.varvec) = new VariableList(); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 163 "parser.yy"
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yysemantic_stack_[(1) - (1)].var_declaration)); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 164 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].varvec)->push_back((yysemantic_stack_[(3) - (3)].var_declaration)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 167 "parser.yy"
    { (yyval.var_declaration) = new NVar_declaration((yysemantic_stack_[(2) - (1)].type), (yysemantic_stack_[(2) - (2)].name)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 170 "parser.yy"
    {(yyval.block) = new NBlock((yysemantic_stack_[(4) - (2)].varvec), (yysemantic_stack_[(4) - (3)].statvec)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 173 "parser.yy"
    { (yyval.varvec) = new VariableList(); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 174 "parser.yy"
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yysemantic_stack_[(1) - (1)].var_declaration)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 175 "parser.yy"
    { (yysemantic_stack_[(2) - (1)].varvec)->push_back((yysemantic_stack_[(2) - (2)].var_declaration)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 178 "parser.yy"
    { (yyval.var_declaration) = new NVar_declaration((yysemantic_stack_[(3) - (1)].type), yylval.name); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 181 "parser.yy"
    { (yyval.type) = new NType_int(); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 182 "parser.yy"
    { (yyval.type) = new NType_char(); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 184 "parser.yy"
    { (yyval.type) = new NType_array((yysemantic_stack_[(4) - (1)].type), (yysemantic_stack_[(4) - (3)].exp)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 187 "parser.yy"
    { (yyval.statvec) = new StatementList(); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 188 "parser.yy"
    { (yyval.statvec) = new StatementList(); (yyval.statvec)->push_back((yysemantic_stack_[(2) - (1)].statement)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 189 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].statvec)->push_back((yysemantic_stack_[(3) - (2)].statement)); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 192 "parser.yy"
    { (yyval.statement) = new NStatement_if((yysemantic_stack_[(5) - (3)].exp), (yysemantic_stack_[(5) - (5)].statement)); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 193 "parser.yy"
    { (yyval.statement) = new NStatement_if_double((yysemantic_stack_[(7) - (3)].exp), (yysemantic_stack_[(7) - (5)].statement), (yysemantic_stack_[(7) - (7)].statement)); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 194 "parser.yy"
    { (yyval.statement) = new NStatement_while((yysemantic_stack_[(5) - (3)].exp), (yysemantic_stack_[(5) - (5)].statement)); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 195 "parser.yy"
    { (yyval.statement) = new NStatement_assign((yysemantic_stack_[(3) - (1)].lexp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 196 "parser.yy"
    { (yyval.statement) = new NStatement_return((yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 197 "parser.yy"
    { (yyval.statement) = new NFunction_call((yysemantic_stack_[(4) - (1)].name), (yysemantic_stack_[(4) - (3)].exprvec)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 198 "parser.yy"
    {(yyval.statement) = (yysemantic_stack_[(1) - (1)].block); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 199 "parser.yy"
    { (yyval.statement) = new NStatement_write((yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 200 "parser.yy"
    { (yyval.statement) = new NStatement_read((yysemantic_stack_[(2) - (2)].lexp)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 203 "parser.yy"
    { (yyval.lexp) = (yysemantic_stack_[(1) - (1)].lexp); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 204 "parser.yy"
    { (yyval.lexp) = new NArray_access((yysemantic_stack_[(4) - (1)].lexp), (yysemantic_stack_[(4) - (3)].exp)); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 208 "parser.yy"
    {(yyval.exp) = (yysemantic_stack_[(1) - (1)].exp); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 209 "parser.yy"
    { (yyval.exp) = new NBinary_op((yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp), (yysemantic_stack_[(3) - (2)].value)); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 210 "parser.yy"
    { (yyval.exp) = new NUnary_op((yysemantic_stack_[(2) - (2)].exp), (yysemantic_stack_[(2) - (1)].value)); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 211 "parser.yy"
    { (yyval.exp) = (yysemantic_stack_[(3) - (2)].exp); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 212 "parser.yy"
    { (yyval.exp) = new NNumber(yylval.value);}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 213 "parser.yy"
    { (yyval.exp) = new NFunction_call((yysemantic_stack_[(4) - (1)].name), (yysemantic_stack_[(4) - (3)].exprvec)); }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 215 "parser.yy"
    { (yyval.exp) = new NLength((yysemantic_stack_[(2) - (2)].lexp)); }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 219 "parser.yy"
    { (yyval.value) = 0; }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 220 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 221 "parser.yy"
    { (yyval.value) = 2; }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 222 "parser.yy"
    { (yyval.value) = 3; }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 223 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 224 "parser.yy"
    { (yyval.value) = 5; }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 225 "parser.yy"
    { (yyval.value) = 6; }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 226 "parser.yy"
    { (yyval.value) = 7; }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 230 "parser.yy"
    { (yyval.value) = 0; }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 231 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 235 "parser.yy"
    { (yyval.exprvec) = new ExpressionList(); }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 236 "parser.yy"
    { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yysemantic_stack_[(1) - (1)].exp)); }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 237 "parser.yy"
    { (yysemantic_stack_[(3) - (1)].exprvec)->push_back((yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 240 "parser.yy"
    { (yyval.var) = new NVar(yylval.name); }
    break;



/* Line 690 of lalr1.cc  */
#line 852 "parser.cc"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  Parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -70;
  const short int
  Parser::yypact_[] =
  {
        26,   -70,   -70,    11,    26,   -70,   -70,     3,   -70,   -70,
     -70,     4,     1,    26,   -70,   -70,     0,     1,    13,   -70,
     -70,    21,   151,     1,   -70,     2,   -70,     5,     1,    97,
     -70,    21,     1,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     1,   183,    29,    26,   -70,   183,    28,   -70,
     167,   183,    26,   -70,   -70,   -70,     1,   -70,    30,   -70,
       6,   183,     7,    36,     1,    41,     1,    13,   -70,   -70,
      71,    35,    37,    40,     1,     1,   183,     1,   183,    21,
     -70,    42,   -70,     1,    33,   116,   135,   -70,   183,   -70,
      75,    75,    61,   -70,    75,   -70
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         7,    19,    18,     0,     2,     3,     4,     0,     1,     5,
       6,     0,     0,     9,    17,    39,    55,     0,     0,    51,
      50,    35,     0,     0,    33,     0,    10,     0,    52,     0,
      55,    41,     0,    49,    48,    47,    20,    46,    43,    42,
      44,    45,     0,    37,     0,     0,    12,    53,     0,    38,
       0,    36,    14,     8,    11,    40,     0,    34,    21,    15,
       0,    54,    55,     0,     0,     0,     0,     0,    30,    16,
       0,     0,     0,     0,    52,     0,    28,     0,    31,    32,
      13,     0,    22,     0,     0,     0,     0,    23,    27,    29,
       0,     0,    24,    26,     0,    25
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -70,   -70,   -70,    66,   -70,    32,    27,   -70,    -2,    -7,
     -70,   -69,   -18,    -9,   -70,   -70,     9,   -70
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     3,     4,     5,    25,    26,    68,    58,     6,     7,
      70,    71,    21,    47,    42,    23,    48,    24
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        31,    81,    10,    22,    15,    16,    27,    11,    29,    46,
      73,     8,    28,    17,    43,    44,    13,    30,    18,    74,
      19,    92,    93,    50,    12,    95,    12,    12,    45,    14,
      20,     1,     2,    51,    62,     1,     2,    63,    27,    64,
      72,    55,    32,    52,    52,    60,    89,    61,    75,    79,
      59,    60,    72,    77,    56,    76,    69,    78,    32,    56,
      82,    83,    65,    66,    67,    14,    85,    87,    86,    94,
       9,    53,    72,    72,    88,    62,    72,    54,    63,    62,
      64,     0,    63,    84,    64,    52,    80,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,     0,    65,    66,    67,
      49,     0,     0,    33,     0,    34,     0,    35,     0,     0,
      37,     0,     0,     0,     0,    38,    39,    40,    41,    90,
       0,     0,    33,     0,    34,     0,    35,     0,     0,    37,
       0,     0,     0,     0,    38,    39,    40,    41,    91,     0,
       0,    33,     0,    34,     0,    35,     0,     0,    37,     0,
       0,     0,     0,    38,    39,    40,    41,    33,     0,    34,
       0,    35,     0,    36,    37,     0,     0,     0,     0,    38,
      39,    40,    41,    33,     0,    34,     0,    35,     0,    57,
      37,     0,     0,     0,     0,    38,    39,    40,    41,    33,
       0,    34,     0,    35,     0,     0,    37,     0,     0,     0,
       0,    38,    39,    40,    41
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        18,    70,     4,    12,     3,     4,    13,     4,    17,     4,
       4,     0,    12,    12,    23,    13,    12,     4,    17,    12,
      19,    90,    91,    32,    21,    94,    21,    21,    26,    25,
      29,     5,     6,    42,     4,     5,     6,     7,    45,     9,
      58,    13,    21,    14,    14,    52,    13,    56,    12,    67,
      52,    58,    70,    12,    26,    64,    58,    66,    21,    26,
      25,    24,    32,    33,    34,    25,    75,    25,    77,     8,
       4,    44,    90,    91,    83,     4,    94,    45,     7,     4,
       9,    -1,     7,    74,     9,    14,    15,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    -1,    32,    33,    34,
      13,    -1,    -1,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    13,
      -1,    -1,    16,    -1,    18,    -1,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    13,    -1,
      -1,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    16,    -1,    18,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    16,    -1,    18,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     5,     6,    38,    39,    40,    45,    46,     0,    40,
      45,     4,    21,    12,    25,     3,     4,    12,    17,    19,
      29,    49,    50,    52,    54,    41,    42,    46,    12,    50,
       4,    49,    21,    16,    18,    20,    22,    23,    28,    29,
      30,    31,    51,    50,    13,    26,     4,    50,    53,    13,
      50,    50,    14,    43,    42,    13,    26,    22,    44,    45,
      46,    50,     4,     7,     9,    32,    33,    34,    43,    45,
      47,    48,    49,     4,    12,    12,    50,    12,    50,    49,
      15,    48,    25,    24,    53,    50,    50,    25,    50,    13,
      13,    13,    48,    48,     8,    48
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
     285,   286,   287,   288,   289,   290,   291
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    37,    38,    39,    39,    39,    39,    39,    40,    41,
      41,    41,    42,    43,    44,    44,    44,    45,    46,    46,
      46,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    53,    54
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     2,     2,     0,     6,     0,
       1,     3,     2,     4,     0,     1,     2,     3,     1,     1,
       4,     0,     2,     3,     5,     7,     5,     3,     2,     4,
       1,     2,     2,     1,     4,     1,     3,     2,     3,     1,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NUMBER", "NAME", "QCHAR",
  "INT", "IF", "ELSE", "RETURN", "FLOAT", "STRUCT", "LPAR", "RPAR",
  "LBRACE", "RBRACE", "LESS", "LENGTH", "GREATER", "NOT", "NEQUAL",
  "LBRACK", "RBRACK", "EQUAL", "ASSIGN", "SEMICOLON", "COMMA", "DOT",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "WHILE", "WRITE", "READ", "LOW",
  "UMINUS", "$accept", "program", "declarations", "fun_declaration",
  "formal_pars", "formal_par", "block", "var_declarations",
  "var_declaration", "type", "statements", "statement", "lexp", "exp",
  "binop", "unop", "pars", "var", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        38,     0,    -1,    39,    -1,    40,    -1,    45,    -1,    39,
      40,    -1,    39,    45,    -1,    -1,    46,     4,    12,    41,
      13,    43,    -1,    -1,    42,    -1,    41,    26,    42,    -1,
      46,     4,    -1,    14,    44,    47,    15,    -1,    -1,    45,
      -1,    44,    45,    -1,    46,     4,    25,    -1,     6,    -1,
       5,    -1,    46,    21,    50,    22,    -1,    -1,    48,    25,
      -1,    47,    48,    25,    -1,     7,    12,    50,    13,    48,
      -1,     7,    12,    50,    13,    48,     8,    48,    -1,    32,
      12,    50,    13,    48,    -1,    49,    24,    50,    -1,     9,
      50,    -1,     4,    12,    53,    13,    -1,    43,    -1,    33,
      50,    -1,    34,    49,    -1,    54,    -1,    49,    21,    50,
      22,    -1,    49,    -1,    50,    51,    50,    -1,    52,    50,
      -1,    12,    50,    13,    -1,     3,    -1,     4,    12,    53,
      13,    -1,    17,    49,    -1,    29,    -1,    28,    -1,    30,
      -1,    31,    -1,    23,    -1,    20,    -1,    18,    -1,    16,
      -1,    29,    -1,    19,    -1,    -1,    50,    -1,    53,    26,
      50,    -1,     4,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    12,    15,    16,    23,
      24,    26,    30,    33,    38,    39,    41,    44,    48,    50,
      52,    57,    58,    61,    65,    71,    79,    85,    89,    92,
      97,    99,   102,   105,   107,   112,   114,   118,   121,   125,
     127,   132,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,   156,   158,   162
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   130,   130,   141,   142,   143,   144,   145,   157,   162,
     163,   164,   167,   170,   173,   174,   175,   178,   181,   182,
     183,   187,   188,   189,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   203,   204,   208,   209,   210,   211,   212,
     213,   215,   219,   220,   221,   222,   223,   224,   225,   226,
     230,   231,   235,   236,   237,   240
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
      35,    36
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 214;
  const int Parser::yynnts_ = 18;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 8;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 37;

  const unsigned int Parser::yyuser_token_number_max_ = 291;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // miniC

/* Line 1136 of lalr1.cc  */
#line 1446 "parser.cc"


/* Line 1138 of lalr1.cc  */
#line 244 "parser.yy"
 /*** Additional Code ***/

void miniC::Parser::error(const Parser::location_type& l,
			  const std::string& m)
{
    driver.error(l, m);
}

