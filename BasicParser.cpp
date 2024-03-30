// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "BISON.txt"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include "FlexLexer.h"

int lineno();

#line 51 "BasicParser.cpp"


#include "BasicParser.hpp"


// Unqualified %code blocks.
#line 35 "BISON.txt"

    #include "BasicScanner.hpp"
    #define yylex(x) scanner->lex(x)

#line 63 "BasicParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 17 "BISON.txt"
namespace basic {
#line 137 "BasicParser.cpp"

  /// Build a parser object.
  Parser::Parser (Scanner* scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STR: // STR
        value.copy< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STR: // STR
        value.move< char* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STR: // STR
        value.YY_MOVE_OR_COPY< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STR: // STR
        value.move< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_STR: // STR
        value.copy< char* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< char > (that.value);
        break;

      case symbol_kind::S_STR: // STR
        value.move< char* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_VARIABLE: // VARIABLE
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_STR: // STR
        yylhs.value.emplace< char* > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< int > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: block
#line 42 "BISON.txt"
                                                            {std::cout << "BISON:OK" << std::endl;}
#line 690 "BasicParser.cpp"
    break;

  case 3: // block: block line
#line 45 "BISON.txt"
                                                            {std::cout << "BISON:BLOCK LINE" << std::endl;}
#line 696 "BasicParser.cpp"
    break;

  case 4: // block: line
#line 46 "BISON.txt"
                                                                {std::cout << "BISON:LINE" << std::endl;}
#line 702 "BasicParser.cpp"
    break;

  case 5: // line: number statement
#line 49 "BISON.txt"
                                                            {std::cout << "BISON:NUMBER_STAT" << std::endl;}
#line 708 "BasicParser.cpp"
    break;

  case 6: // line: statement
#line 50 "BISON.txt"
                                                                {std::cout << "BISON:STAT" << std::endl;}
#line 714 "BasicParser.cpp"
    break;

  case 7: // statement: PRINT expr_list EOL
#line 54 "BISON.txt"
                                                            {std::cout << "BISON:PRINT" << std::endl;}
#line 720 "BasicParser.cpp"
    break;

  case 8: // statement: REM string EOL
#line 55 "BISON.txt"
                                                            {std::cout << "BISON:REM" << std::endl;}
#line 726 "BasicParser.cpp"
    break;

  case 9: // statement: DIM var_list EOL
#line 56 "BISON.txt"
                                                            {std::cout << "BISON:DIM" << std::endl;}
#line 732 "BasicParser.cpp"
    break;

  case 10: // statement: IF expression relop expression THEN statement EOL
#line 57 "BISON.txt"
                                                            {std::cout << "BISON:IF_THEN" << std::endl;}
#line 738 "BasicParser.cpp"
    break;

  case 11: // statement: GOSUB expression EOL
#line 58 "BISON.txt"
                                                            {std::cout << "BISON:GOSUB" << std::endl;}
#line 744 "BasicParser.cpp"
    break;

  case 12: // statement: INPUT var_list EOL
#line 59 "BISON.txt"
                                                            {std::cout << "BISON:INPUT" << std::endl;}
#line 750 "BasicParser.cpp"
    break;

  case 13: // statement: LET var EQ expression EOL
#line 60 "BISON.txt"
                                                            {std::cout << "BISON:LET" << std::endl;}
#line 756 "BasicParser.cpp"
    break;

  case 14: // statement: RETURN EOL
#line 61 "BISON.txt"
                                                            {std::cout << "BISON:RETURN" << lineno() << std::endl;}
#line 762 "BasicParser.cpp"
    break;

  case 15: // expr_list: expr_list ',' expression
#line 65 "BISON.txt"
                                                            {std::cout << "BISON:EXPR_LIST EXPR" << std::endl;}
#line 768 "BasicParser.cpp"
    break;

  case 16: // expr_list: expression
#line 66 "BISON.txt"
                                                                {std::cout << "BISON:EXPR" << std::endl;}
#line 774 "BasicParser.cpp"
    break;

  case 17: // expr_list: string
#line 67 "BISON.txt"
                                                                {std::cout << "BISON:STRING" << std::endl;}
#line 780 "BasicParser.cpp"
    break;

  case 18: // expr_list: expr_list ',' string
#line 68 "BISON.txt"
                                                            {std::cout << "BISON:EXPR_LIST STR" << std::endl;}
#line 786 "BasicParser.cpp"
    break;

  case 19: // var_list: var_list ',' var
#line 72 "BISON.txt"
                                                            {std::cout << "BISON:VAR_LIST VAR" << std::endl;}
#line 792 "BasicParser.cpp"
    break;

  case 20: // var_list: var
#line 73 "BISON.txt"
                                                            {std::cout << "BISON:VAR" << std::endl;}
#line 798 "BasicParser.cpp"
    break;

  case 21: // expression: expression '+' term
#line 77 "BISON.txt"
                                                            {std::cout << "BISON:EXPR+TERM" << std::endl;}
#line 804 "BasicParser.cpp"
    break;

  case 22: // expression: expression '-' term
#line 78 "BISON.txt"
                                                            {std::cout << "BISON:EXPR-TERM" << std::endl;}
#line 810 "BasicParser.cpp"
    break;

  case 23: // expression: term
#line 79 "BISON.txt"
                                                            {std::cout << "BISON:TERM" << std::endl;}
#line 816 "BasicParser.cpp"
    break;

  case 24: // term: term '*' factor
#line 83 "BISON.txt"
                                                            {std::cout << "BISON:TERM*FACTOR" << std::endl;}
#line 822 "BasicParser.cpp"
    break;

  case 25: // term: term '/' factor
#line 84 "BISON.txt"
                                                            {std::cout << "BISON:TERM/FACTOR" << std::endl;}
#line 828 "BasicParser.cpp"
    break;

  case 26: // term: factor
#line 85 "BISON.txt"
                                                            {std::cout << "BISON:FACTOR" << std::endl;}
#line 834 "BasicParser.cpp"
    break;

  case 27: // factor: var
#line 89 "BISON.txt"
                                                            {std::cout << "BISON:FACTOR_VAR" << std::endl;}
#line 840 "BasicParser.cpp"
    break;

  case 28: // factor: number
#line 90 "BISON.txt"
                                                            {std::cout << "BISON:NUMBER" << std::endl;}
#line 846 "BasicParser.cpp"
    break;

  case 29: // factor: '(' expression ')'
#line 91 "BISON.txt"
                                                            {std::cout << "BISON:(EXPR)" << std::endl;}
#line 852 "BasicParser.cpp"
    break;

  case 30: // number: number digit
#line 95 "BISON.txt"
                                                            {std::cout << "BISON:NUMBER_DIGIT" << std::endl;}
#line 858 "BasicParser.cpp"
    break;

  case 31: // number: digit
#line 96 "BISON.txt"
                                                            {std::cout << "BISON:DIGIT" << std::endl;}
#line 864 "BasicParser.cpp"
    break;

  case 32: // digit: INTEGER
#line 100 "BISON.txt"
                                                            {std::cout << "BISON:INT" << std::endl;}
#line 870 "BasicParser.cpp"
    break;

  case 33: // var: VARIABLE
#line 104 "BISON.txt"
                                                            {std::cout << "BISON:VARIABLE" << std::endl;}
#line 876 "BasicParser.cpp"
    break;

  case 34: // string: STR
#line 107 "BISON.txt"
                                                            {std::cout << "BISON:STR" << std::endl;}
#line 882 "BasicParser.cpp"
    break;

  case 35: // relop: LT
#line 111 "BISON.txt"
                                                            {std::cout << "BISON:LT" << std::endl;}
#line 888 "BasicParser.cpp"
    break;

  case 36: // relop: LE
#line 112 "BISON.txt"
                                                                {std::cout << "BISON:LE" << std::endl;}
#line 894 "BasicParser.cpp"
    break;

  case 37: // relop: GT
#line 113 "BISON.txt"
                                                                {std::cout << "BISON:GT" << std::endl;}
#line 900 "BasicParser.cpp"
    break;

  case 38: // relop: GE
#line 114 "BISON.txt"
                                                            {std::cout << "BISON:GE" << std::endl;}
#line 906 "BasicParser.cpp"
    break;

  case 39: // relop: EQ
#line 115 "BISON.txt"
                                                            {std::cout << "BISON:EQ" << std::endl;}
#line 912 "BasicParser.cpp"
    break;

  case 40: // relop: NE
#line 116 "BISON.txt"
                                                            {std::cout << "BISON:NE" << std::endl;}
#line 918 "BasicParser.cpp"
    break;


#line 922 "BasicParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -22;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      13,   -22,     6,    23,     2,    12,    12,    23,    23,   -21,
      33,    13,   -22,   -22,    13,   -22,   -22,   -22,    12,    22,
      24,    46,   -22,     9,   -22,   -22,    54,   -22,    15,    50,
       7,    56,    19,   -22,   -22,   -22,   -22,   -22,    17,   -22,
       6,    12,    12,    12,    12,   -22,    23,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,    12,   -22,   -22,    12,   -22,    24,
     -22,    46,    46,   -22,   -22,   -22,    -1,    37,    49,   -22,
      38,   -22
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     6,     0,    31,    34,    33,     0,     0,
      16,    23,    26,    28,    27,    17,     0,    20,     0,     0,
       0,     0,     0,    14,     1,     3,     5,    30,     0,     7,
       0,     0,     0,     0,     0,     9,     0,     8,    35,    36,
      37,    38,    39,    40,     0,    11,    12,     0,    29,    15,
      18,    21,    22,    24,    25,    19,     0,     0,     0,    13,
       0,    10
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -22,   -22,   -22,    27,   -14,   -22,    59,    -4,    42,    43,
      18,    16,     0,     1,   -22
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,    10,    11,    12,    13,    19,    26,    20,    21,    22,
      23,    15,    24,    25,    54
  };

  const signed char
  Parser::yytable_[] =
  {
      36,    29,    30,    27,    33,    28,    16,    27,    32,     1,
      16,    17,     1,    68,    38,     1,     1,    17,    14,     2,
       3,     4,     5,     6,     7,     8,    41,    42,    17,    14,
      37,     9,    55,    34,    41,    42,    59,    18,    35,    37,
      47,    60,    57,    18,    41,    42,    65,    39,    40,    58,
      66,    41,    42,    67,    70,     2,     3,     4,     5,     6,
       7,     8,    69,    71,    41,    42,    31,     9,     0,    48,
      49,    50,    51,    52,    53,    43,    44,    41,    42,    45,
      46,    56,    46,    61,    62,     0,    63,    64
  };

  const signed char
  Parser::yycheck_[] =
  {
      14,     5,     6,     3,    25,     4,     4,     7,     8,     3,
       4,     5,     3,    14,    18,     3,     3,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    27,    28,     5,    11,
      14,    18,    25,     0,    27,    28,    40,    31,    11,    23,
      25,    40,    23,    31,    27,    28,    46,    25,    26,    32,
      54,    27,    28,    57,    68,     6,     7,     8,     9,    10,
      11,    12,    25,    25,    27,    28,     7,    18,    -1,    19,
      20,    21,    22,    23,    24,    29,    30,    27,    28,    25,
      26,    25,    26,    41,    42,    -1,    43,    44
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     6,     7,     8,     9,    10,    11,    12,    18,
      34,    35,    36,    37,    43,    44,     4,     5,    31,    38,
      40,    41,    42,    43,    45,    46,    39,    45,    46,    40,
      40,    39,    45,    25,     0,    36,    37,    44,    40,    25,
      26,    27,    28,    29,    30,    25,    26,    25,    19,    20,
      21,    22,    23,    24,    47,    25,    25,    23,    32,    40,
      46,    41,    41,    42,    42,    45,    40,    40,    14,    25,
      37,    25
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    37,    37,    37,    38,    38,    38,    38,    39,
      39,    40,    40,    40,    41,    41,    41,    42,    42,    42,
      43,    43,    44,    45,    46,    47,    47,    47,    47,    47,
      47
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     3,     3,     3,
       7,     3,     3,     5,     2,     3,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "STR",
  "VARIABLE", "PRINT", "DIM", "REM", "IF", "GOSUB", "INPUT", "LET", "END",
  "THEN", "LIST", "CLEAR", "RUN", "RETURN", "LT", "LE", "GT", "GE", "EQ",
  "NE", "EOL", "','", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "$accept",
  "program", "block", "line", "statement", "expr_list", "var_list",
  "expression", "term", "factor", "number", "digit", "var", "string",
  "relop", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  Parser::yyrline_[] =
  {
       0,    42,    42,    45,    46,    49,    50,    54,    55,    56,
      57,    58,    59,    60,    61,    65,    66,    67,    68,    72,
      73,    77,    78,    79,    83,    84,    85,    89,    90,    91,
      95,    96,   100,   104,   107,   111,   112,   113,   114,   115,
     116
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    29,    27,    26,    28,     2,    30,     2,     2,
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
      25
    };
    // Last valid token kind.
    const int code_max = 280;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 17 "BISON.txt"
} // basic
#line 1320 "BasicParser.cpp"

#line 119 "BISON.txt"


void basic::Parser::error(const std::string& msg)
{
    std::cerr << msg << '\n';
}
