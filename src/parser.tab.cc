// A Bison parser, made by GNU Bison 3.8.2.

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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 28 "parser.y"


    class Lexer: public yyFlexLexer {
    public:
        yy::location yylloc;

        Lexer (ifstream& fin, string* fname) : yyFlexLexer (fin, cout) {
            yylloc.initialize (fname, 1, 1);
        }

        void update_loc ()
        {
            yylloc.step ();
            yylloc.end.column += yyleng;
        }

        void update_loc_mc ()
        {
            const string& s = yytext;

            for (const char& c: s)
            {
                if (c == '\n')
                    yylloc.begin.line = ++yylloc.end.line,
                    yylloc.begin.column = yylloc.end.column = 1;

                else
                    yylloc.begin.column = ++yylloc.end.column;
            }
        }

        yy::parser::symbol_type scan ();
    };

    yy::parser::symbol_type yylex (ifstream& fin, string* filename) {
        static Lexer lexer (fin, filename);
        // lexer.set_debug (true);
        return lexer.scan ();
    }

    void yy::parser::error (const location& loc, const std::string& msg) {
        cerr << loc << " " << msg;
    }

#line 91 "parser.tab.cc"


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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

#line 5 "parser.y"
namespace yy {
#line 184 "parser.tab.cc"

  /// Build a parser object.
  parser::parser (ifstream& fin_yyarg, string* filename_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      fin (fin_yyarg),
      filename (filename_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.YY_MOVE_OR_COPY< long double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.YY_MOVE_OR_COPY< long long int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.move< long double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< long long int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.copy< long double > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.copy< long long int > (that.value);
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.move< long double > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< long long int > (that.value);
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (fin, filename));
            yyla.move (yylookahead);
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        yylhs.value.emplace< long double > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        yylhs.value.emplace< long long int > ();
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: classes
#line 160 "parser.y"
                 {cout << "Valid program!\n"; }
#line 695 "parser.tab.cc"
    break;

  case 53: // expression: expression "+" expression
#line 257 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 701 "parser.tab.cc"
    break;

  case 54: // expression: expression "-" expression
#line 258 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::MINUS, yystack_[0].value.as < Expression* > ())}
#line 707 "parser.tab.cc"
    break;

  case 55: // expression: expression "*" expression
#line 259 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::MULTIPLY, yystack_[0].value.as < Expression* > ())}
#line 713 "parser.tab.cc"
    break;

  case 56: // expression: expression "/" expression
#line 260 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::DIVIDE, yystack_[0].value.as < Expression* > ())}
#line 719 "parser.tab.cc"
    break;

  case 57: // expression: expression "%" expression
#line 261 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::MODULO, yystack_[0].value.as < Expression* > ())}
#line 725 "parser.tab.cc"
    break;

  case 58: // expression: expression "|" expression
#line 262 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::BIT_OR, yystack_[0].value.as < Expression* > ())}
#line 731 "parser.tab.cc"
    break;

  case 59: // expression: expression "&" expression
#line 263 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::BIT_AND, yystack_[0].value.as < Expression* > ())}
#line 737 "parser.tab.cc"
    break;

  case 60: // expression: expression "^" expression
#line 264 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::BIT_XOR, yystack_[0].value.as < Expression* > ())}
#line 743 "parser.tab.cc"
    break;

  case 61: // expression: expression "<<" expression
#line 265 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::LEFT_SHIFT, yystack_[0].value.as < Expression* > ())}
#line 749 "parser.tab.cc"
    break;

  case 62: // expression: expression ">>" expression
#line 266 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::RIGHT_SHIFT, yystack_[0].value.as < Expression* > ())}
#line 755 "parser.tab.cc"
    break;

  case 63: // expression: expression "||" expression
#line 267 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::BIT_OR, yystack_[0].value.as < Expression* > ())}
#line 761 "parser.tab.cc"
    break;

  case 64: // expression: expression "&&" expression
#line 268 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::BIT_AND, yystack_[0].value.as < Expression* > ())}
#line 767 "parser.tab.cc"
    break;

  case 65: // expression: expression ">" expression
#line 269 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::GREATER, yystack_[0].value.as < Expression* > ())}
#line 773 "parser.tab.cc"
    break;

  case 66: // expression: expression "<" expression
#line 270 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::LESSER, yystack_[0].value.as < Expression* > ())}
#line 779 "parser.tab.cc"
    break;

  case 67: // expression: expression ">=" expression
#line 271 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 785 "parser.tab.cc"
    break;

  case 68: // expression: expression "<=" expression
#line 272 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 791 "parser.tab.cc"
    break;

  case 69: // expression: expression "==" expression
#line 273 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 797 "parser.tab.cc"
    break;

  case 70: // expression: expression "!=" expression
#line 274 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 803 "parser.tab.cc"
    break;

  case 71: // expression: expression "," expression
#line 275 "parser.y"
                                        {yylhs.value.as < Expression* > () = new BinaryExpresssion (yystack_[2].value.as < Expression* > (), token::PLUS, yystack_[0].value.as < Expression* > ())}
#line 809 "parser.tab.cc"
    break;

  case 72: // expression: IDENTIFIER "=" expression
#line 276 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 815 "parser.tab.cc"
    break;

  case 73: // expression: IDENTIFIER "+=" expression
#line 277 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::PLUS_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 821 "parser.tab.cc"
    break;

  case 74: // expression: IDENTIFIER "-=" expression
#line 278 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::MINUS_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 827 "parser.tab.cc"
    break;

  case 75: // expression: IDENTIFIER "*=" expression
#line 279 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::MULTIPLY_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 833 "parser.tab.cc"
    break;

  case 76: // expression: IDENTIFIER "/=" expression
#line 280 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::DIVIDE_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 839 "parser.tab.cc"
    break;

  case 77: // expression: IDENTIFIER "%=" expression
#line 281 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::MODULO_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 845 "parser.tab.cc"
    break;

  case 78: // expression: IDENTIFIER "&=" expression
#line 282 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::BIT_AND_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 851 "parser.tab.cc"
    break;

  case 79: // expression: IDENTIFIER "|=" expression
#line 283 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::BIT_OR_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 857 "parser.tab.cc"
    break;

  case 80: // expression: IDENTIFIER "^=" expression
#line 284 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::BIT_XOR_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 863 "parser.tab.cc"
    break;

  case 81: // expression: IDENTIFIER "<<=" expression
#line 285 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::LEFT_SHIFT_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 869 "parser.tab.cc"
    break;

  case 82: // expression: IDENTIFIER ">>=" expression
#line 286 "parser.y"
                                        { yylhs.value.as < Expression* > () = new AssignmentExpression (yystack_[2].value.as < string > (), token::RIGHT_SHIFT_ASSIGNMENT, yystack_[0].value.as < Expression* > ())}
#line 875 "parser.tab.cc"
    break;

  case 95: // expression: INTEGER_LITERAL
#line 299 "parser.y"
                            { yylhs.value.as < Expression* > () = new IntegerLiteralExpression (yystack_[0].value.as < long long int > ()) }
#line 881 "parser.tab.cc"
    break;

  case 96: // expression: FLOATING_LITERAL
#line 300 "parser.y"
                             { yylhs.value.as < Expression* > () = new FloatingLiteralExpression (yystack_[0].value.as < long double > ()) }
#line 887 "parser.tab.cc"
    break;

  case 97: // expression: BOOLEAN_LITERAL
#line 301 "parser.y"
                            { yylhs.value.as < Expression* > () = new BooleanLiteralExpression (yystack_[0].value.as < bool > ()) }
#line 893 "parser.tab.cc"
    break;

  case 98: // expression: STRING_LITERAL
#line 302 "parser.y"
                           { yylhs.value.as < Expression* > () = new StringLiteralExpression (yystack_[0].value.as < string > ()) }
#line 899 "parser.tab.cc"
    break;


#line 903 "parser.tab.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "class", "return", "public",
  "protected", "private", "constructor", "destructor", "if", "else", "{",
  "}", "(", ")", ".", ":", ";", ",", "UNKNOWN", "+", "-", "*", "/", "%",
  "++", "--", ">", "<", ">=", "<=", "==", "!=", "||", "&&", "!", "|", "&",
  "^", "~", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=",
  "^=", "<<=", ">>=", "INTEGER_LITERAL", "FLOATING_LITERAL",
  "BOOLEAN_LITERAL", "STRING_LITERAL", "IDENTIFIER", "UMINUS", "UPLUS",
  "ADDRESS_OF", "DEREFERENCE", "PRE_INCREMENT", "PRE_DECREMENT",
  "POST_INCREMENT", "POST_DECREMENT", "$accept", "program", "classes",
  "classDef", "optionalSemicolons", "classMembers", "accessSpecifiers",
  "functionDeclarations", "function", "parameters", "parametersList",
  "constructorDef", "destructorDef", "variableDeclarations", "init",
  "moreVariableDeclarations", "memberAccess", "functionCall", "arguments",
  "argumentsList", "ifStatement", "ifElseStatement", "elseIfStatement",
  "elseStatement", "statements", "statement", "expression", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -43;

  const short
  parser::yypact_[] =
  {
     -66,     8,    -2,   -66,   -54,   -66,    -1,   -27,   -15,    73,
      17,   -66,    45,   -66,    72,    75,    76,     1,   326,   -66,
      78,   -66,   -66,   -66,    80,    83,    43,   -66,   -66,   -66,
     326,   326,   326,    52,    53,    54,   326,    56,   326,   -66,
     -66,   -66,   -66,   349,   -66,   100,   534,    61,   -66,    62,
     104,   107,    78,   388,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   326,    64,   -66,   -66,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,    64,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   -66,    66,    67,
     111,   108,   116,    62,   -66,   114,   117,   512,     3,   -66,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   -66,   534,    59,    59,   -66,   -66,   -66,     4,     4,
       4,     4,   659,   659,   556,   578,   600,   644,   622,    84,
      84,    45,   -66,   126,    82,   -66,   127,   -66,   326,   -66,
     -66,    86,    77,   129,   534,   133,   -66,   303,   131,   -66,
     -66,   -11,   -66,   137,   -66,   -66,   463,   -66,   -66,   -66,
     488,   326,   138,   -66,   182,   -66,   413,    -8,   -66,   -66,
     140,   326,   -66,   -66,   438,   231,   145,   -66,   -66,   280,
     -66
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     3,     0,    15,     0,     0,
      13,     8,    27,     7,     0,     0,     0,     0,     0,    29,
       5,    10,    12,    11,     0,     0,     0,     7,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    30,    94,    31,    26,     0,     6,    20,
       0,     0,    14,     0,    83,    84,    87,    89,    90,    85,
      88,    86,    36,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    19,     0,    20,    93,     0,    35,    38,    30,    32,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    33,    71,    53,    54,    55,    56,    57,    65,    66,
      67,    68,    69,    70,    63,    64,    58,    59,    60,    61,
      62,    27,    21,     0,     0,    45,     0,    34,     0,    28,
      45,     0,     0,     0,    37,     0,    22,     0,     0,    24,
      52,    30,    46,    47,    48,    44,     0,    45,    23,    51,
       0,     0,     0,    49,     0,    50,     0,     0,    40,    16,
       0,     0,    41,    45,     0,     0,     0,    39,    45,     0,
      43
  };

  const short
  parser::yypgoto_[] =
  {
     -66,   -66,   -66,   -66,   123,   -66,   -66,   -66,   -66,    55,
     -66,   -66,   -66,   154,    21,   -66,   -56,   -66,   -66,   -66,
     -13,   -66,   -66,   -66,   -65,   -66,   -18
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     5,    20,     9,    17,    10,    27,   100,
     101,    28,    29,   162,    19,    47,    44,    45,   105,   106,
     163,   164,   172,   178,   152,   165,   166
  };

  const short
  parser::yytable_[] =
  {
      46,     4,   158,    62,     6,    63,   181,   109,     3,    24,
      25,     7,    53,    54,    55,    64,    65,    62,    59,    63,
      61,   121,    14,    15,    16,    79,    80,    81,    82,    83,
      -9,     8,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    12,   107,    95,    96,    12,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    26,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    97,
      98,   157,    81,    82,    83,   155,    13,   158,    18,    21,
     159,    30,    22,    23,    49,   160,    48,    50,    31,    32,
      33,    51,   174,    34,    35,    79,    80,    81,    82,    83,
      56,    57,    58,    36,    60,    37,    77,    38,   185,   102,
      99,   103,   108,   189,   141,   142,   143,   144,   145,   147,
     154,    39,    40,    41,    42,   161,   148,   157,   150,   170,
     151,   167,   153,   158,   156,   171,   168,    30,   -42,   177,
      52,   160,   183,   176,    31,    32,    33,   188,   146,    34,
      35,    11,   149,   184,   182,     0,     0,     0,     0,    36,
       0,    37,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,    39,    40,    41,
      42,   161,   158,     0,     0,   179,    30,     0,     0,     0,
     160,     0,     0,    31,    32,    33,     0,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      37,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,    39,    40,    41,    42,
     161,   158,     0,     0,   187,    30,     0,     0,     0,   160,
       0,     0,    31,    32,    33,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    37,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,    39,    40,    41,    42,   161,
     158,     0,     0,   190,    30,     0,     0,     0,   160,     0,
       0,    31,    32,    33,     0,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    30,    37,     0,
      38,   169,     0,     0,    31,    32,    33,     0,     0,    34,
      35,     0,     0,     0,    39,    40,    41,    42,   161,    36,
      30,    37,     0,    38,     0,     0,     0,    31,    32,    33,
       0,     0,    34,    35,     0,     0,     0,    39,    40,    41,
      42,    43,    36,    62,    37,    63,    38,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   104,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    94,   180,    95,
      96,     0,    78,     0,    79,    80,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,   186,    95,    96,     0,    78,     0,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    94,     0,    95,
      96,   173,    78,     0,    79,    80,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,     0,    95,    96,   175,    78,     0,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    94,     0,    95,
      96,    78,     0,    79,    80,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,     0,    95,    96,    79,    80,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,    93,    94,     0,    95,    96,    79,    80,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    88,    89,
       0,    91,     0,    92,    93,    94,     0,    95,    96,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    92,    93,    94,     0,    95,
      96,    79,    80,    81,    82,    83,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,    93,    94,
       0,    95,    96,    79,    80,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    88,    89,     0,     0,     0,     0,
      93,     0,     0,    95,    96,    79,    80,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    89,     0,     0,
      79,    80,    81,    82,    83,    95,    96,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96
  };

  const short
  parser::yycheck_[] =
  {
      18,     3,    10,    14,    58,    16,    14,    63,     0,     8,
       9,    12,    30,    31,    32,    26,    27,    14,    36,    16,
      38,    77,     5,     6,     7,    21,    22,    23,    24,    25,
      13,    58,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    58,    62,    41,    42,    58,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    58,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    18,
      19,     4,    23,    24,    25,   150,    13,    10,    43,    17,
      13,    14,    17,    17,    14,    18,    18,    14,    21,    22,
      23,    58,   167,    26,    27,    21,    22,    23,    24,    25,
      58,    58,    58,    36,    58,    38,    16,    40,   183,    15,
      58,    14,    58,   188,    58,    58,    15,    19,    12,    15,
     148,    54,    55,    56,    57,    58,    19,     4,    12,   157,
      58,    12,    15,    10,    58,    14,    13,    14,    11,    11,
      27,    18,    12,   171,    21,    22,    23,    12,   103,    26,
      27,     7,   141,   181,   177,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    54,    55,    56,
      57,    58,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    54,    55,    56,    57,
      58,    10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    54,    55,    56,    57,    58,
      10,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    14,    38,    -1,
      40,    18,    -1,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    -1,    -1,    -1,    54,    55,    56,    57,    58,    36,
      14,    38,    -1,    40,    -1,    -1,    -1,    21,    22,    23,
      -1,    -1,    26,    27,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    36,    14,    38,    16,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    15,    41,
      42,    -1,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    15,    41,    42,    -1,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    41,
      42,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    -1,    41,    42,    18,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    41,
      42,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    -1,    41,    42,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    -1,    41,    42,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    35,    -1,    37,    38,    39,    -1,    41,    42,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      42,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    42,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      21,    22,    23,    24,    25,    41,    42,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    68,    69,     0,     3,    70,    58,    12,    58,    72,
      74,    80,    58,    13,     5,     6,     7,    73,    43,    81,
      71,    17,    17,    17,     8,     9,    58,    75,    78,    79,
      14,    21,    22,    23,    26,    27,    36,    38,    40,    54,
      55,    56,    57,    58,    83,    84,    93,    82,    18,    14,
      14,    58,    71,    93,    93,    93,    58,    58,    58,    93,
      58,    93,    14,    16,    26,    27,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    16,    19,    21,
      22,    23,    24,    25,    28,    29,    30,    31,    32,    33,
      34,    35,    37,    38,    39,    41,    42,    18,    19,    58,
      76,    77,    15,    14,    15,    85,    86,    93,    58,    83,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    83,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    58,    58,    15,    19,    12,    76,    15,    19,    81,
      12,    58,    91,    15,    93,    91,    58,     4,    10,    13,
      18,    58,    80,    87,    88,    92,    93,    12,    13,    18,
      93,    14,    89,    18,    91,    18,    93,    11,    90,    13,
      15,    14,    87,    12,    93,    91,    15,    13,    12,    91,
      13
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    67,    68,    69,    69,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    78,    79,    80,    81,    81,    82,    82,
      83,    83,    83,    83,    84,    85,    85,    86,    86,    87,
      88,    89,    89,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     6,     2,     0,     1,     1,
       2,     2,     2,     0,     4,     0,     8,     1,     1,     1,
       0,     2,     4,     7,     6,     5,     2,     0,     4,     0,
       1,     1,     3,     3,     4,     1,     0,     3,     1,     7,
       3,     3,     0,     7,     2,     0,     1,     1,     1,     2,
       3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   160,   160,   163,   164,   167,   170,   171,   174,   175,
     178,   179,   180,   181,   184,   185,   188,   189,   190,   193,
     194,   197,   198,   201,   203,   205,   208,   209,   212,   213,
     216,   217,   218,   219,   222,   224,   225,   228,   229,   232,
     234,   237,   238,   241,   244,   245,   248,   249,   250,   251,
     252,   253,   254,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302
  };

  void
  parser::yy_stack_print_ () const
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
  parser::yy_reduce_print_ (int yyrule) const
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


#line 5 "parser.y"
} // yy
#line 1696 "parser.tab.cc"

#line 304 "parser.y"


int main (int argc, char** argv) {

    string filename = argv[1];
    ifstream fin (filename);

    yy::parser p(fin, &filename);
    /* p.set_debug_level(1); */

    p.parse ();

    return 0;
}
