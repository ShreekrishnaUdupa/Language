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





// "%code requires" blocks.
#line 17 "parser.y"

    #include <iostream>
    #include <string>
    #include <fstream>
    #include "ast.hpp"

    using namespace std;

#line 52 "parser.cpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hpp"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "parser.y"
namespace yy {
#line 188 "parser.cpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // BOOLEAN_LITERAL
      char dummy1[sizeof (bool)];

      // FLOATING_LITERAL
      char dummy2[sizeof (long double)];

      // INTEGER_LITERAL
      char dummy3[sizeof (long long int)];

      // STRING_LITERAL
      // IDENTIFIER
      char dummy4[sizeof (string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    CLASS = 258,                   // "class"
    RETURN = 259,                  // "return"
    PUBLIC = 260,                  // "public"
    PROTECTED = 261,               // "protected"
    PRIVATE = 262,                 // "private"
    CONSTRUCTOR = 263,             // "constructor"
    DESTRUCTOR = 264,              // "destructor"
    IF = 265,                      // "if"
    ELSE = 266,                    // "else"
    LBRACE = 267,                  // "{"
    RBRACE = 268,                  // "}"
    LPAREN = 269,                  // "("
    RPAREN = 270,                  // ")"
    DOT = 271,                     // "."
    COLON = 272,                   // ":"
    SEMICOLON = 273,               // ";"
    COMMA = 274,                   // ","
    UNKNOWN = 275,                 // UNKNOWN
    PLUS = 276,                    // "+"
    MINUS = 277,                   // "-"
    MULTIPLY = 278,                // "*"
    DIVIDE = 279,                  // "/"
    MODULO = 280,                  // "%"
    INCREMENT = 281,               // "++"
    DECREMENT = 282,               // "--"
    GREATER = 283,                 // ">"
    LESSER = 284,                  // "<"
    GE = 285,                      // ">="
    LE = 286,                      // "<="
    E = 287,                       // "=="
    NE = 288,                      // "!="
    LOGICAL_OR = 289,              // "||"
    LOGICAL_AND = 290,             // "&&"
    LOGICAL_NOT = 291,             // "!"
    BIT_OR = 292,                  // "|"
    BIT_AND = 293,                 // "&"
    BIT_XOR = 294,                 // "^"
    BIT_NOT = 295,                 // "~"
    LEFT_SHIFT = 296,              // "<<"
    RIGHT_SHIFT = 297,             // ">>"
    ASSIGNMENT = 298,              // "="
    PLUS_ASSIGNMENT = 299,         // "+="
    MINUS_ASSIGNMENT = 300,        // "-="
    MULTIPLY_ASSIGNMENT = 301,     // "*="
    DIVIDE_ASSIGNMENT = 302,       // "/="
    MODULO_ASSIGNMENT = 303,       // "%="
    BIT_AND_ASSIGNMENT = 304,      // "&="
    BIT_OR_ASSIGNMENT = 305,       // "|="
    BIT_XOR_ASSIGNMENT = 306,      // "^="
    LEFT_SHIFT_ASSIGNMENT = 307,   // "<<="
    RIGHT_SHIFT_ASSIGNMENT = 308,  // ">>="
    INTEGER_LITERAL = 309,         // INTEGER_LITERAL
    FLOATING_LITERAL = 310,        // FLOATING_LITERAL
    BOOLEAN_LITERAL = 311,         // BOOLEAN_LITERAL
    STRING_LITERAL = 312,          // STRING_LITERAL
    IDENTIFIER = 313,              // IDENTIFIER
    UMINUS = 314,                  // UMINUS
    UPLUS = 315,                   // UPLUS
    ADDRESS_OF = 316,              // ADDRESS_OF
    DEREFERENCE = 317,             // DEREFERENCE
    PRE_INCREMENT = 318,           // PRE_INCREMENT
    PRE_DECREMENT = 319,           // PRE_DECREMENT
    POST_INCREMENT = 320,          // POST_INCREMENT
    POST_DECREMENT = 321           // POST_DECREMENT
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 67, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_CLASS = 3,                             // "class"
        S_RETURN = 4,                            // "return"
        S_PUBLIC = 5,                            // "public"
        S_PROTECTED = 6,                         // "protected"
        S_PRIVATE = 7,                           // "private"
        S_CONSTRUCTOR = 8,                       // "constructor"
        S_DESTRUCTOR = 9,                        // "destructor"
        S_IF = 10,                               // "if"
        S_ELSE = 11,                             // "else"
        S_LBRACE = 12,                           // "{"
        S_RBRACE = 13,                           // "}"
        S_LPAREN = 14,                           // "("
        S_RPAREN = 15,                           // ")"
        S_DOT = 16,                              // "."
        S_COLON = 17,                            // ":"
        S_SEMICOLON = 18,                        // ";"
        S_COMMA = 19,                            // ","
        S_UNKNOWN = 20,                          // UNKNOWN
        S_PLUS = 21,                             // "+"
        S_MINUS = 22,                            // "-"
        S_MULTIPLY = 23,                         // "*"
        S_DIVIDE = 24,                           // "/"
        S_MODULO = 25,                           // "%"
        S_INCREMENT = 26,                        // "++"
        S_DECREMENT = 27,                        // "--"
        S_GREATER = 28,                          // ">"
        S_LESSER = 29,                           // "<"
        S_GE = 30,                               // ">="
        S_LE = 31,                               // "<="
        S_E = 32,                                // "=="
        S_NE = 33,                               // "!="
        S_LOGICAL_OR = 34,                       // "||"
        S_LOGICAL_AND = 35,                      // "&&"
        S_LOGICAL_NOT = 36,                      // "!"
        S_BIT_OR = 37,                           // "|"
        S_BIT_AND = 38,                          // "&"
        S_BIT_XOR = 39,                          // "^"
        S_BIT_NOT = 40,                          // "~"
        S_LEFT_SHIFT = 41,                       // "<<"
        S_RIGHT_SHIFT = 42,                      // ">>"
        S_ASSIGNMENT = 43,                       // "="
        S_PLUS_ASSIGNMENT = 44,                  // "+="
        S_MINUS_ASSIGNMENT = 45,                 // "-="
        S_MULTIPLY_ASSIGNMENT = 46,              // "*="
        S_DIVIDE_ASSIGNMENT = 47,                // "/="
        S_MODULO_ASSIGNMENT = 48,                // "%="
        S_BIT_AND_ASSIGNMENT = 49,               // "&="
        S_BIT_OR_ASSIGNMENT = 50,                // "|="
        S_BIT_XOR_ASSIGNMENT = 51,               // "^="
        S_LEFT_SHIFT_ASSIGNMENT = 52,            // "<<="
        S_RIGHT_SHIFT_ASSIGNMENT = 53,           // ">>="
        S_INTEGER_LITERAL = 54,                  // INTEGER_LITERAL
        S_FLOATING_LITERAL = 55,                 // FLOATING_LITERAL
        S_BOOLEAN_LITERAL = 56,                  // BOOLEAN_LITERAL
        S_STRING_LITERAL = 57,                   // STRING_LITERAL
        S_IDENTIFIER = 58,                       // IDENTIFIER
        S_UMINUS = 59,                           // UMINUS
        S_UPLUS = 60,                            // UPLUS
        S_ADDRESS_OF = 61,                       // ADDRESS_OF
        S_DEREFERENCE = 62,                      // DEREFERENCE
        S_PRE_INCREMENT = 63,                    // PRE_INCREMENT
        S_PRE_DECREMENT = 64,                    // PRE_DECREMENT
        S_POST_INCREMENT = 65,                   // POST_INCREMENT
        S_POST_DECREMENT = 66,                   // POST_DECREMENT
        S_YYACCEPT = 67,                         // $accept
        S_program = 68,                          // program
        S_classes = 69,                          // classes
        S_classDef = 70,                         // classDef
        S_optionalSemicolons = 71,               // optionalSemicolons
        S_accessSpecifiers = 72,                 // accessSpecifiers
        S_functions = 73,                        // functions
        S_function = 74,                         // function
        S_parameters = 75,                       // parameters
        S_parametersList = 76,                   // parametersList
        S_constructorDef = 77,                   // constructorDef
        S_destructorDef = 78,                    // destructorDef
        S_variableDeclarations = 79,             // variableDeclarations
        S_init = 80,                             // init
        S_moreVariableDeclarations = 81,         // moreVariableDeclarations
        S_functionCall = 82,                     // functionCall
        S_arguments = 83,                        // arguments
        S_argumentsList = 84,                    // argumentsList
        S_ifStatement = 85,                      // ifStatement
        S_ifElseStatement = 86,                  // ifElseStatement
        S_elseIfStatement = 87,                  // elseIfStatement
        S_elseStatement = 88,                    // elseStatement
        S_statements = 89,                       // statements
        S_statement = 90,                        // statement
        S_expression = 91                        // expression
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.move< long double > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< long long int > (std::move (that.value));
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.template destroy< long double > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.template destroy< long long int > ();
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.template destroy< string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long double v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const long double& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const long long int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (ifstream& fin_yyarg, string* filename_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (location_type l)
      {
        return symbol_type (token::CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const location_type& l)
      {
        return symbol_type (token::CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (location_type l)
      {
        return symbol_type (token::PUBLIC, std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC (const location_type& l)
      {
        return symbol_type (token::PUBLIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROTECTED (location_type l)
      {
        return symbol_type (token::PROTECTED, std::move (l));
      }
#else
      static
      symbol_type
      make_PROTECTED (const location_type& l)
      {
        return symbol_type (token::PROTECTED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIVATE (location_type l)
      {
        return symbol_type (token::PRIVATE, std::move (l));
      }
#else
      static
      symbol_type
      make_PRIVATE (const location_type& l)
      {
        return symbol_type (token::PRIVATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTRUCTOR (location_type l)
      {
        return symbol_type (token::CONSTRUCTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_CONSTRUCTOR (const location_type& l)
      {
        return symbol_type (token::CONSTRUCTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DESTRUCTOR (location_type l)
      {
        return symbol_type (token::DESTRUCTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_DESTRUCTOR (const location_type& l)
      {
        return symbol_type (token::DESTRUCTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNKNOWN (location_type l)
      {
        return symbol_type (token::UNKNOWN, std::move (l));
      }
#else
      static
      symbol_type
      make_UNKNOWN (const location_type& l)
      {
        return symbol_type (token::UNKNOWN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTIPLY (location_type l)
      {
        return symbol_type (token::MULTIPLY, std::move (l));
      }
#else
      static
      symbol_type
      make_MULTIPLY (const location_type& l)
      {
        return symbol_type (token::MULTIPLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (location_type l)
      {
        return symbol_type (token::DIVIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const location_type& l)
      {
        return symbol_type (token::DIVIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULO (location_type l)
      {
        return symbol_type (token::MODULO, std::move (l));
      }
#else
      static
      symbol_type
      make_MODULO (const location_type& l)
      {
        return symbol_type (token::MODULO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCREMENT (location_type l)
      {
        return symbol_type (token::INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_INCREMENT (const location_type& l)
      {
        return symbol_type (token::INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECREMENT (location_type l)
      {
        return symbol_type (token::DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DECREMENT (const location_type& l)
      {
        return symbol_type (token::DECREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSER (location_type l)
      {
        return symbol_type (token::LESSER, std::move (l));
      }
#else
      static
      symbol_type
      make_LESSER (const location_type& l)
      {
        return symbol_type (token::LESSER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_E (location_type l)
      {
        return symbol_type (token::E, std::move (l));
      }
#else
      static
      symbol_type
      make_E (const location_type& l)
      {
        return symbol_type (token::E, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL_OR (location_type l)
      {
        return symbol_type (token::LOGICAL_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGICAL_OR (const location_type& l)
      {
        return symbol_type (token::LOGICAL_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL_AND (location_type l)
      {
        return symbol_type (token::LOGICAL_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGICAL_AND (const location_type& l)
      {
        return symbol_type (token::LOGICAL_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL_NOT (location_type l)
      {
        return symbol_type (token::LOGICAL_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGICAL_NOT (const location_type& l)
      {
        return symbol_type (token::LOGICAL_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_OR (location_type l)
      {
        return symbol_type (token::BIT_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_OR (const location_type& l)
      {
        return symbol_type (token::BIT_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_AND (location_type l)
      {
        return symbol_type (token::BIT_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_AND (const location_type& l)
      {
        return symbol_type (token::BIT_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_XOR (location_type l)
      {
        return symbol_type (token::BIT_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_XOR (const location_type& l)
      {
        return symbol_type (token::BIT_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_NOT (location_type l)
      {
        return symbol_type (token::BIT_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_NOT (const location_type& l)
      {
        return symbol_type (token::BIT_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_SHIFT (location_type l)
      {
        return symbol_type (token::LEFT_SHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_SHIFT (const location_type& l)
      {
        return symbol_type (token::LEFT_SHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_SHIFT (location_type l)
      {
        return symbol_type (token::RIGHT_SHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_SHIFT (const location_type& l)
      {
        return symbol_type (token::RIGHT_SHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::PLUS_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::PLUS_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::MINUS_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::MINUS_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTIPLY_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::MULTIPLY_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_MULTIPLY_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::MULTIPLY_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::DIVIDE_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::DIVIDE_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULO_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::MODULO_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_MODULO_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::MODULO_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_AND_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::BIT_AND_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_AND_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::BIT_AND_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_OR_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::BIT_OR_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_OR_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::BIT_OR_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_XOR_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::BIT_XOR_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_XOR_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::BIT_XOR_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_SHIFT_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::LEFT_SHIFT_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_SHIFT_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::LEFT_SHIFT_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_SHIFT_ASSIGNMENT (location_type l)
      {
        return symbol_type (token::RIGHT_SHIFT_ASSIGNMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_SHIFT_ASSIGNMENT (const location_type& l)
      {
        return symbol_type (token::RIGHT_SHIFT_ASSIGNMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER_LITERAL (long long int v, location_type l)
      {
        return symbol_type (token::INTEGER_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER_LITERAL (const long long int& v, const location_type& l)
      {
        return symbol_type (token::INTEGER_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOATING_LITERAL (long double v, location_type l)
      {
        return symbol_type (token::FLOATING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOATING_LITERAL (const long double& v, const location_type& l)
      {
        return symbol_type (token::FLOATING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN_LITERAL (bool v, location_type l)
      {
        return symbol_type (token::BOOLEAN_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN_LITERAL (const bool& v, const location_type& l)
      {
        return symbol_type (token::BOOLEAN_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (string v, location_type l)
      {
        return symbol_type (token::STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const string& v, const location_type& l)
      {
        return symbol_type (token::STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (string v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const string& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::UMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UPLUS (location_type l)
      {
        return symbol_type (token::UPLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UPLUS (const location_type& l)
      {
        return symbol_type (token::UPLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS_OF (location_type l)
      {
        return symbol_type (token::ADDRESS_OF, std::move (l));
      }
#else
      static
      symbol_type
      make_ADDRESS_OF (const location_type& l)
      {
        return symbol_type (token::ADDRESS_OF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEREFERENCE (location_type l)
      {
        return symbol_type (token::DEREFERENCE, std::move (l));
      }
#else
      static
      symbol_type
      make_DEREFERENCE (const location_type& l)
      {
        return symbol_type (token::DEREFERENCE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRE_INCREMENT (location_type l)
      {
        return symbol_type (token::PRE_INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRE_INCREMENT (const location_type& l)
      {
        return symbol_type (token::PRE_INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRE_DECREMENT (location_type l)
      {
        return symbol_type (token::PRE_DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRE_DECREMENT (const location_type& l)
      {
        return symbol_type (token::PRE_DECREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POST_INCREMENT (location_type l)
      {
        return symbol_type (token::POST_INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_POST_INCREMENT (const location_type& l)
      {
        return symbol_type (token::POST_INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POST_DECREMENT (location_type l)
      {
        return symbol_type (token::POST_DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_POST_DECREMENT (const location_type& l)
      {
        return symbol_type (token::POST_DECREMENT, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 662,     ///< Last index in yytable_.
      yynnts_ = 25,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    ifstream& fin;
    string* filename;

  };

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
    };
    // Last valid token kind.
    const int code_max = 321;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.copy< long double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.copy< long long int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_BOOLEAN_LITERAL: // BOOLEAN_LITERAL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOATING_LITERAL: // FLOATING_LITERAL
        value.move< long double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< long long int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 5 "parser.y"
} // yy
#line 2516 "parser.cpp"






// Unqualified %code blocks.
#line 26 "parser.y"


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
        // lexer.set_debug (1);
        return lexer.scan ();
    }

    void yy::parser::error (const location& loc, const std::string& msg) {
        cerr << loc << " " << msg;
    }

#line 2569 "parser.cpp"


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
#line 2662 "parser.cpp"

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
#line 154 "parser.y"
                 {cout << "Valid program!\n"; }
#line 3153 "parser.cpp"
    break;


#line 3157 "parser.cpp"

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
  "classDef", "optionalSemicolons", "accessSpecifiers", "functions",
  "function", "parameters", "parametersList", "constructorDef",
  "destructorDef", "variableDeclarations", "init",
  "moreVariableDeclarations", "functionCall", "arguments", "argumentsList",
  "ifStatement", "ifElseStatement", "elseIfStatement", "elseStatement",
  "statements", "statement", "expression", YY_NULLPTR
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


  const signed char parser::yypact_ninf_ = -48;

  const signed char parser::yytable_ninf_ = -37;

  const short
  parser::yypact_[] =
  {
     -48,     1,     6,   -48,   -47,   -48,     8,   -48,    27,     4,
      11,    12,   -48,    18,   -48,   -48,   -48,    -5,    28,    29,
      -3,   -48,   -48,   -48,   -48,    -2,    42,    63,    -5,    20,
      71,    68,    78,    -2,   -48,    79,    34,   -48,    80,   -48,
      41,    75,    88,   130,   -48,   300,    94,   -48,   356,   -48,
     356,   356,    51,    52,    54,   356,    56,   356,   -48,   -48,
     -48,   -48,   316,   -48,   -48,   105,   -48,   -48,   466,   -48,
     -48,   -48,   128,   488,   356,   394,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   356,   -48,   -48,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,    74,   107,
     -48,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   179,
     -48,   419,   -48,   106,   101,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   356,   -48,    -4,
     -48,    14,    14,   -48,   -48,   -48,    82,    82,    82,    82,
      -6,    -6,   532,   554,   576,   620,   598,    59,    59,   -48,
     113,   -48,   356,   510,   -15,   356,   -48,   -48,   510,   -48,
      69,   444,   228,    74,   114,   -48,   -48,   -48,   277,   -48
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     3,     0,    13,    11,     0,
       0,     0,     7,     0,     8,    10,     9,     5,     0,     0,
       0,     7,    15,    16,     6,    18,     0,     0,    12,     0,
       0,    17,     0,    18,    19,     0,     0,    39,     0,    39,
       0,     0,     0,     0,    20,     0,     0,    22,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,    88,    40,    87,    41,    42,    38,     0,    39,
      21,    45,    88,     0,     0,     0,    76,    77,    80,    82,
      83,    78,    81,    79,    30,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    86,     0,    29,    32,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    27,     0,
      34,    47,    48,    49,    50,    51,    54,    55,    61,    62,
      63,    64,    59,    60,    52,    53,    56,    57,    58,    14,
       0,    28,     0,    24,     0,     0,    35,    39,    31,    23,
       0,     0,     0,    25,     0,    33,    26,    39,     0,    37
  };

  const signed char
  parser::yypgoto_[] =
  {
     -48,   -48,   -48,   -48,   115,   -48,   -48,   -48,   102,   -48,
     -48,   -48,   -48,   -36,   -48,   -48,   -48,   -48,     0,   -48,
     -48,   -48,   -39,   -48,   -43
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     5,    17,    13,     8,    21,    30,    31,
      22,    23,    63,   138,   164,    64,   123,   124,    65,    66,
      99,   140,    41,    67,    68
  };

  const short
  parser::yytable_[] =
  {
      43,     3,    73,   169,   170,    75,    46,    76,    77,     4,
     165,     6,    81,    24,    83,   101,   102,   103,   104,   105,
       7,    14,   106,   107,   108,   109,    18,    19,    15,    16,
     119,   121,     9,    10,    11,   117,   118,   103,   104,   105,
      12,   125,    25,    26,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    27,    29,    32,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    20,    33,    34,    45,
     101,   102,   103,   104,   105,    46,    35,    36,    47,    48,
      37,    39,    40,    49,   163,    42,    50,    51,    52,    44,
      69,    53,    54,   101,   102,   103,   104,   105,    74,    78,
      79,    55,    80,    56,    82,    57,   -36,   137,   139,   168,
     162,   161,   171,   117,   118,   167,   177,   173,   172,    58,
      59,    60,    61,    62,    45,    38,    28,   176,   178,   166,
      46,     0,    84,    70,    48,     0,     0,     0,    49,     0,
       0,    50,    51,    52,    85,    86,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,     0,
      57,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,    45,    58,    59,    60,    61,    62,    46,
       0,     0,   159,    48,     0,     0,     0,    49,     0,     0,
      50,    51,    52,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    58,    59,    60,    61,    62,    46,     0,
       0,   175,    48,     0,     0,     0,    49,     0,     0,    50,
      51,    52,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    58,    59,    60,    61,    62,    46,     0,     0,
     179,    48,     0,     0,     0,    49,     0,     0,    50,    51,
      52,     0,     0,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    48,    56,     0,    57,    71,     0,
       0,    50,    51,    52,     0,     0,    53,    54,     0,     0,
      84,    58,    59,    60,    61,    62,    55,     0,    56,     0,
      57,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    72,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      48,     0,     0,     0,    98,     0,     0,    50,    51,    52,
       0,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
      58,    59,    60,    61,    72,   101,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,   116,   160,   117,   118,     0,     0,     0,
     101,   102,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   174,
     117,   118,     0,     0,     0,   101,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,   116,   100,   117,   118,   101,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,     0,   114,   115,   116,   120,   117,   118,   101,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,     0,   114,   115,   116,     0,   117,
     118,   101,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
       0,   117,   118,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,     0,   113,     0,   114,
     115,   116,     0,   117,   118,   101,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   114,   115,   116,     0,   117,   118,   101,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   115,   116,     0,   117,   118,   101,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   115,     0,     0,   117,
     118,   101,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,   117,   118
  };

  const short
  parser::yycheck_[] =
  {
      39,     0,    45,    18,    19,    48,    10,    50,    51,     3,
      14,    58,    55,    18,    57,    21,    22,    23,    24,    25,
      12,    17,    28,    29,    30,    31,     8,     9,    17,    17,
      69,    74,     5,     6,     7,    41,    42,    23,    24,    25,
      13,    84,    14,    14,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    58,    58,    15,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    58,    14,    58,     4,
      21,    22,    23,    24,    25,    10,    15,    19,    13,    14,
      12,    12,    58,    18,   137,    15,    21,    22,    23,    58,
      12,    26,    27,    21,    22,    23,    24,    25,    14,    58,
      58,    36,    58,    38,    58,    40,    11,    43,    11,   162,
      19,    15,   165,    41,    42,    12,    12,    58,   167,    54,
      55,    56,    57,    58,     4,    33,    21,   173,   177,   139,
      10,    -1,    14,    13,    14,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    26,    27,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,     4,    54,    55,    56,    57,    58,    10,
      -1,    -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,
      21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    54,    55,    56,    57,    58,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    54,    55,    56,    57,    58,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    14,    38,    -1,    40,    18,    -1,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      14,    54,    55,    56,    57,    58,    36,    -1,    38,    -1,
      40,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      14,    -1,    -1,    -1,    58,    -1,    -1,    21,    22,    23,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      54,    55,    56,    57,    58,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    15,    41,    42,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    15,
      41,    42,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    18,    41,    42,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    38,    39,    18,    41,    42,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    41,
      42,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    38,    39,
      -1,    41,    42,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    35,    -1,    37,
      38,    39,    -1,    41,    42,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    42,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    68,    69,     0,     3,    70,    58,    12,    73,     5,
       6,     7,    13,    72,    17,    17,    17,    71,     8,     9,
      58,    74,    77,    78,    18,    14,    14,    58,    71,    58,
      75,    76,    15,    14,    58,    15,    19,    12,    75,    12,
      58,    89,    15,    89,    58,     4,    10,    13,    14,    18,
      21,    22,    23,    26,    27,    36,    38,    40,    54,    55,
      56,    57,    58,    79,    82,    85,    86,    90,    91,    12,
      13,    18,    58,    91,    14,    91,    91,    91,    58,    58,
      58,    91,    58,    91,    14,    26,    27,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    58,    87,
      18,    21,    22,    23,    24,    25,    28,    29,    30,    31,
      32,    33,    34,    35,    37,    38,    39,    41,    42,    89,
      18,    91,    15,    83,    84,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    43,    80,    11,
      88,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    13,
      15,    15,    19,    91,    81,    14,    85,    12,    91,    18,
      19,    91,    89,    58,    15,    13,    80,    12,    89,    13
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    67,    68,    69,    69,    70,    71,    71,    72,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    83,
      83,    84,    84,    85,    86,    87,    87,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     6,     2,     0,     2,     2,
       2,     0,     4,     0,     8,     1,     1,     1,     0,     2,
       4,     7,     6,     5,     2,     0,     4,     0,     4,     1,
       0,     3,     1,     7,     3,     3,     0,     7,     2,     0,
       1,     1,     1,     2,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   154,   154,   157,   158,   161,   165,   166,   169,   170,
     171,   172,   175,   176,   179,   180,   181,   184,   185,   188,
     189,   192,   194,   196,   199,   200,   203,   204,   207,   209,
     210,   213,   214,   217,   219,   222,   223,   226,   229,   230,
     233,   234,   235,   236,   237,   238,   239,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
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
#line 3936 "parser.cpp"

#line 289 "parser.y"


int main () {

    string filename ("file.anial");
    ifstream fin ("file.anial");

    yy::parser p(fin, &filename);
    p.parse ();

    return 0;
}
