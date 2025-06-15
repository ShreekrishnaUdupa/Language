%language "c++"
%skeleton "lalr1.cc"
%require "3.2"

%define api.namespace {yy}
%define api.parser.class {parser}
%define api.token.constructor
%define api.value.type variant
%define parse.error detailed
%define parse.lac full
%locations
%define api.location.file "location.hpp"

%parse-param {ifstream& fin} {string* filename}
%lex-param   {ifstream& fin} {string* filename}

%code requires {
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <variant>

    using namespace std;
}

%code {

    class Lexer: public yyFlexLexer {
    public:
        yy::location yylloc;

        Lexer (ifstream& fin, string* fname) : yyFlexLexer (fin, cout) {
            yylloc.initialize (fname, 1, 1);
        }

        void update_loc () {
            yylloc.step ();
            yylloc.end.column += yyleng;
            cout << yytext << '\t' << yylloc << '\n';
        }

        yy::parser::symbol_type scan ();
    };

    yy::parser::symbol_type yylex (ifstream& fin, string* filename) {
        static Lexer lexer (fin, filename);
        return lexer.scan ();
    }

    void yy::parser::error (const location& loc, const std::string& msg) {
        cerr << loc << msg;
    }
}

%token CLASS "class"
%token TOKEN_Main "Main"
%token TOKEN_main "main"
%token VOID "void"
%token RETURN "return"
%token PUBLIC "public"
%token PROTECTED "protected"
%token PRIVATE "private"
%token LBRACE "{"
%token RBRACE "}"
%token LPAREN "("
%token RPAREN ")"
%token DOT "."

%token SEMICOLON ";"
%token COMMA ","
%token UNKNOWN

%token PLUS "+" 
%token MINUS "-"
%token MULTIPLY "*"
%token DIVIDE "/"
%token MODULO "%"
%token INCREMENT "++"
%token DECREMENT "--"

%token GREATER ">"
%token LESSER "<"
%token GE ">="
%token LE "<="
%token E "=="
%token NE "!="

%token LOGICAL_OR "||"
%token LOGICAL_AND "&&"
%token LOGICAL_NOT "!"

%token BIT_OR "|"
%token BIT_AND "&"
%token BIT_XOR "^"
%token BIT_NOT "~"
%token LEFT_SHIFT "<<"
%token RIGHT_SHIFT ">>"

%token ASSIGNMENT "="
%token PLUS_ASSIGNMENT "+="
%token MINUS_ASSIGNMENT "-="
%token MULTIPLY_ASSIGNMENT "*="
%token DIVIDE_ASSIGNMENT "/="
%token MODULO_ASSIGNMENT "%="
%token BIT_AND_ASSIGNMENT "&="
%token BIT_OR_ASSIGNMENT "|="
%token BIT_XOR_ASSIGNMENT "^="
%token LEFT_SHIFT_ASSIGNMENT "<<="
%token RIGHT_SHIFT_ASSIGNMENT ">>="
%token YYEOF 0

%token <int> INTEGER_LITERAL
%token <double> FLOATING_LITERAL
%token <string> STRING_LITERAL
%token <string> IDENTIFIER

%left ","
%right "=" "+=" "-=" "*=" "/=" "%=" "&=" "|=" "^=" "<<=" ">>="
%left "||"
%left "&&"
%left "|"
%left "^"
%left "&"
%left "==" "!="
%left "<" "<=" ">" ">="
%left "<<" ">>"
%left "+" "-"
%left "*" "/" "%"
%right "!" "~" UMINUS UPLUS ADDRESS_OF DEREFERENCE PRE_INCREMENT PRE_DECREMENT
%left POST_INCREMENT POST_DECREMENT
%left "("

%start program

%%
program: classes mainClass classes YYEOF {cout << "Valid program!\n"; }
       ;

mainClass: "class" "Main" "{" "void" "main" "(" ")" "{" statements "}" "}" optionalSemicolons
         ;

classes: classes classDef
       | %empty
       ;

classDef: "class" IDENTIFIER "{" functions "}" optionalSemicolons
        ;

optionalSemicolons: optionalSemicolons ";"
                  | %empty
                  ;

accessSpecifiers: "public" ':'
                | "private" ':'
                | "protected" ':'
                | %empty
                ;

functions: functions accessSpecifiers function
         | %empty
         ;

function: IDENTIFIER IDENTIFIER "(" arguments ")" "{" statements "}"
        ;

arguments: argumentList
         | %empty
         ;

argumentList: IDENTIFIER IDENTIFIER
            | argumentList "," IDENTIFIER IDENTIFIER
            ;

statements: statements statement
          | %empty
          ;   

statement: declaration
         | expression ";"
         | "return" expression ";"
         | "return" ";"
         | ";"
         ;

declaration: IDENTIFIER IDENTIFIER init moreDeclarations ";"
           ;

init: "=" expression
    | %empty
    ;

moreDeclarations: moreDeclarations "," IDENTIFIER init
                | %empty
                ;

expression: expression "+" expression
          | expression "-" expression
          | expression "*" expression
          | expression "/" expression
          | expression "%" expression
          | expression "|" expression
          | expression "&" expression
          | expression ">" expression
          | expression "<" expression
          | expression "^" expression
          | expression "<<" expression
          | expression ">>" expression
          | expression "||" expression
          | expression "&&" expression
          | expression ">=" expression
          | expression "<=" expression
          | expression "==" expression
          | expression "!=" expression
          | "+" expression %prec UPLUS
          | "-" expression %prec UMINUS
          | "!" expression
          | "~" expression
          | "*" IDENTIFIER %prec DEREFERENCE
          | "&" IDENTIFIER %prec ADDRESS_OF
          | "++" IDENTIFIER %prec PRE_INCREMENT
          | "--" IDENTIFIER %prec PRE_DECREMENT
          | IDENTIFIER "++" %prec POST_INCREMENT
          | IDENTIFIER "--" %prec POST_DECREMENT
          | IDENTIFIER "=" expression
          | IDENTIFIER "+=" expression
          | IDENTIFIER "-=" expression
          | IDENTIFIER "*=" expression
          | IDENTIFIER "/=" expression
          | IDENTIFIER "%=" expression
          | IDENTIFIER "&=" expression
          | IDENTIFIER "|=" expression
          | IDENTIFIER "^=" expression
          | IDENTIFIER "<<=" expression
          | IDENTIFIER ">>=" expression
          | "(" expression ")"
          | IDENTIFIER
          | INTEGER_LITERAL
          | FLOATING_LITERAL
          ;
%%

int main () {

    string filename ("file.anial");
    ifstream fin ("file.anial");

    yy::parser p(fin, &filename);
    p.parse ();

    return 0;
}