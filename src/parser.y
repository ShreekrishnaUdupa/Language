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
    using token = yy::parser::token;
}

%code {

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

%nterm <Expression*> expression
%nterm <Statement*> statement
%nterm <vector<Statement*>> statements
%nterm <vector<Parameter*>> parametersList
%nterm <FunctionDeclaration*> functionDeclaration
%nterm <VariableDeclartios


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

%glr-parser
%expect 2
%start program

%%
program: classes {cout << "Valid program!\n"; }
       ;

classes: classes classDef
       | %empty
       ;

classDef: "class" IDENTIFIER "{" classMembers "}" optionalSemicolons
        ;

optionalSemicolons: optionalSemicolons ";"
                  | %empty
                  ;

classMembers: classMembers classMember
            | %empty
            ;

classMember: variableDeclarations
           | functionDeclarations
           ;


// Needs fixing regarding functionDeclarations and all

accessSpecifiers: "public" ":"
                | "private" ":"
                | "protected" ":"
                | %empty
                ;

functionDeclarations: accessSpecifiers functionDeclarations function optionalSemicolons
         | 
         ;

function: accessSpecifiers IDENTIFIER IDENTIFIER "(" parameters ")" "{" statements "}" optionalSemicolons
        | constructorDeclaration
        | destructorDef
        ;

// ---------- //

parameters: parametersList
		  | %empty
		  ;

parametersList: IDENTIFIER IDENTIFIER
			  | parametersList "," IDENTIFIER IDENTIFIER
			  ;

constructorDeclaration: "constructor" "(" parameters ")" "{" statements "}"

destructorDef: "destructor" "(" ")" "{" statements "}"

variableDeclarations: IDENTIFIER IDENTIFIER init moreVariableDeclarations ";" optionalSemicolons
                    {
                        vector<VariableDeclaration*> vars;
                        vars.push_back(new VariableDeclaration($1, $2, $3));
                        vars.insert(vars.end(), $4.begin(), $4.end());

                        for (size_t i = 1; i < vars.size(); ++i)
                            vars[i]->type = vars[0]->type;
                            
                        $$ = vars;
                    };

init: "=" expression {$$ = $2}
    | %empty {$$ = nullptr}
    ;

moreVariableDeclarations: moreVariableDeclarations "," IDENTIFIER init
                            {
                                $1.push_back(new VariableDeclaration("", $3, $4));
                                $$ = $1;
                            }
                        | %empty {$$ = {}; }
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

expression: expression "+" expression   { $$ = new BinaryExpression ($1, token::PLUS, $3) }
          | expression "-" expression   { $$ = new BinaryExpression ($1, token::MINUS, $3) } 
          | expression "*" expression   { $$ = new BinaryExpression ($1, token::MULTIPLY, $3) }
          | expression "/" expression   { $$ = new BinaryExpression ($1, token::DIVIDE, $3) }
          | expression "%" expression   { $$ = new BinaryExpression ($1, token::MODULO, $3) }
          | expression "|" expression   { $$ = new BinaryExpression ($1, token::BIT_OR, $3) }
          | expression "&" expression   { $$ = new BinaryExpression ($1, token::BIT_AND, $3) }
          | expression "^" expression   { $$ = new BinaryExpression ($1, token::BIT_XOR, $3) }
          | expression "<<" expression  { $$ = new BinaryExpression ($1, token::LEFT_SHIFT, $3) }
          | expression ">>" expression  { $$ = new BinaryExpression ($1, token::RIGHT_SHIFT, $3) }
          | expression "||" expression  { $$ = new BinaryExpression ($1, token::LOGICAL_OR, $3) }
          | expression "&&" expression  { $$ = new BinaryExpression ($1, token::LOGICAL_AND, $3) }
          | expression ">" expression   { $$ = new BinaryExpression ($1, token::GREATER, $3) }
          | expression "<" expression   { $$ = new BinaryExpression ($1, token::LESSER, $3) }
          | expression ">=" expression  { $$ = new BinaryExpression ($1, token::GE, $3) }
          | expression "<=" expression  { $$ = new BinaryExpression ($1, token::LE, $3) }
          | expression "==" expression  { $$ = new BinaryExpression ($1, token::E, $3) }
          | expression "!=" expression  { $$ = new BinaryExpression ($1, token::NE, $3) }
          | expression "," expression   { $$ = new BinaryExpression ($1, token::COMMA, $3) }
          | IDENTIFIER "=" expression   { $$ = new AssignmentExpression ($1, token::ASSIGNMENT, $3) }
          | IDENTIFIER "+=" expression  { $$ = new AssignmentExpression ($1, token::PLUS_ASSIGNMENT, $3) }
          | IDENTIFIER "-=" expression  { $$ = new AssignmentExpression ($1, token::MINUS_ASSIGNMENT, $3) }
          | IDENTIFIER "*=" expression  { $$ = new AssignmentExpression ($1, token::MULTIPLY_ASSIGNMENT, $3) }
          | IDENTIFIER "/=" expression  { $$ = new AssignmentExpression ($1, token::DIVIDE_ASSIGNMENT, $3) }
          | IDENTIFIER "%=" expression  { $$ = new AssignmentExpression ($1, token::MODULO_ASSIGNMENT, $3) }
          | IDENTIFIER "&=" expression  { $$ = new AssignmentExpression ($1, token::BIT_AND_ASSIGNMENT, $3) }
          | IDENTIFIER "|=" expression  { $$ = new AssignmentExpression ($1, token::BIT_OR_ASSIGNMENT, $3) }
          | IDENTIFIER "^=" expression  { $$ = new AssignmentExpression ($1, token::BIT_XOR_ASSIGNMENT, $3) }
          | IDENTIFIER "<<=" expression { $$ = new AssignmentExpression ($1, token::LEFT_SHIFT_ASSIGNMENT, $3) }
          | IDENTIFIER ">>=" expression { $$ = new AssignmentExpression ($1, token::RIGHT_SHIFT_ASSIGNMENT, $3) }
          | "+" expression %prec UPLUS              { $$ = new UnaryExpression (token::UPLUS, $2) }
          | "-" expression %prec UMINUS             { $$ = new UnaryExpression (token::UMINUS, $2) }
          | "*" IDENTIFIER %prec DEREFERENCE        { $$ = new UnaryExpression (token::DEREFERENCE, $2) }
          | "&" IDENTIFIER %prec ADDRESS_OF         { $$ = new UnaryExpression (token::ADDRESS_OF, $2) }
          | "++" IDENTIFIER %prec PRE_INCREMENT     { $$ = new UnaryExpression (token::PRE_INCREMENT, $2) }
          | "--" IDENTIFIER %prec PRE_DECREMENT     { $$ = new UnaryExpression (token::PRE_DECREMENT, $2) }
          | IDENTIFIER "++" %prec POST_INCREMENT    { $$ = new UnaryExpression (token::POST_INCREMENT, $1) }
          | IDENTIFIER "--" %prec POST_DECREMENT    { $$ = new UnaryExpression (token::POST_DECREMENT, $1) }
          | "!" expression                          { $$ = new UnaryExpression (token::LOGICAL_NOT, $2) }
          | "~" expression                          { $$ = new UnaryExpression (token::BIT_NOT, $2) }
          | "(" expression ")"                      { $$ = $2 }
          | memberAccess                            { $$ = $1 }
          | INTEGER_LITERAL                         { $$ = new IntegerLiteralExpression ($1) }
          | FLOATING_LITERAL                        { $$ = new FloatingLiteralExpression ($1) }
          | BOOLEAN_LITERAL                         { $$ = new BooleanLiteralExpression ($1) }
          | STRING_LITERAL                          { $$ = new StringLiteralExpression ($1) }
          ;

ifStatement: "if" "(" expression ")" "{" statements "}"

ifElseStatement: ifStatement elseIfStatement elseStatement
               ;

elseIfStatement: elseIfStatement "else" ifStatement
               | %empty
               ;

elseStatement: "else" "(" expression ")" "{" statements "}"
             ;

memberAccess: IDENTIFIER
            | functionCall
            | IDENTIFIER "." memberAccess
            | functionCall "." memberAccess
            ;

functionCall: IDENTIFIER "(" arguments ")"

arguments: argumentsList
         | %empty
         ;

argumentsList: argumentsList "," expression
             | expression
             ;

%%

int main (int argc, char** argv) {

    string filename = argv[1];
    ifstream fin (filename);

    yy::parser p(fin, &filename);
    /* p.set_debug_level(1); */

    p.parse ();

    return 0;
}