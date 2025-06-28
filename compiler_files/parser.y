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
    #include "ast.hpp"

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
            cout << yylloc << " " << yytext << '\n';
        }

        void update_loc_mc () {
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
}

%token CLASS "class"
%token RETURN "return"
%token PUBLIC "public"
%token PROTECTED "protected"
%token PRIVATE "private"
%token CONSTRUCTOR "constructor"
%token DESTRUCTOR "destructor"
%token IF "if"
%token ELSE "else"

%token LBRACE "{"
%token RBRACE "}"
%token LPAREN "("
%token RPAREN ")"
%token DOT "."
%token COLON ":"
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

%token <long long int> INTEGER_LITERAL
%token <long double> FLOATING_LITERAL
%token <bool> BOOLEAN_LITERAL
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
program: classes {cout << "Valid program!\n"; }
       ;

classes: classes classDef
       | %empty
       ;

classDef: "class" IDENTIFIER "{" functions "}" optionalSemicolons
        ;


optionalSemicolons: optionalSemicolons ";"
                  | %empty
                  ;

accessSpecifiers: "public" ":"
                | "private" ":"
                | "protected" ":"
                | %empty
                ;

functions: functions accessSpecifiers function optionalSemicolons
         | %empty
         ;

function: IDENTIFIER IDENTIFIER "(" parameters ")" "{" statements "}"
        | constructorDef
        | destructorDef
        ;

parameters: parametersList
		  | %empty
		  ;

parametersList: IDENTIFIER IDENTIFIER
			  | parametersList "," IDENTIFIER IDENTIFIER
			  ;

constructorDef: "constructor" "(" parameters ")" "{" statements "}"

destructorDef: "destructor" "(" ")" "{" statements "}"

variableDeclarations: IDENTIFIER IDENTIFIER init moreVariableDeclarations ";"
           ;

init: "=" expression
    | %empty
    ;

moreVariableDeclarations: moreVariableDeclarations "," IDENTIFIER init
                | %empty
                ;

functionCall: IDENTIFIER "(" arguments ")"

arguments: argumentsList
         | %empty
         ;

argumentsList: argumentsList "," expression
             | expression
             ;

ifStatement: "if" "(" expression ")" "{" statements "}"

ifElseStatement: ifStatement elseIfStatement elseStatement
               ;

elseIfStatement: elseIfStatement "else" ifStatement
               | %empty
               ;

elseStatement: "else" "(" expression ")" "{" statements "}"
             ;
        
statements: statements statement
          | %empty
          ;

statement: variableDeclarations
         | ifStatement
         | ifElseStatement
         | expression ";"
         | "return" expression ";"
         | "return" ";"
         | ";"
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
          | "(" expression ")"
          | functionCall
          | IDENTIFIER
          | INTEGER_LITERAL
          | FLOATING_LITERAL
          | BOOLEAN_LITERAL
          | STRING_LITERAL
          ;
%%

int main () {

    string filename ("file.anial");
    ifstream fin ("file.anial");

    yy::parser p(fin, &filename);
    p.parse ();

    return 0;
}