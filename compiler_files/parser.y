%define api.namespace {yy}
%define api.parser.class {parser}
%define parse.error verbose
%define api.location.file "location.hh"
%define api.value.type variant
%define parse.trace
%parse-param { yy::Scanner* scanner }

%code requires {
    #include <string>
    using std::string;
}

%code {
    #include <iostream>
    #include <string>
    using std::string;
    using namespace std;

    void yyerror(const char* s) {
        cerr << "Parse error: " << s << " at line " << yylineno << '\n';
    }
}



%start Program

%token <string> IDENTIFIER
%token <string> STRING_LITERAL
%token <int> INTEGER_LITERAL
%token <double> FLOATING_LITERAL

%token <string> CLASS "class"
%token TOKEN_Main "Main"
%token TOKEN_main "main"
%token RETURN "return"
%token PUBLIC "public"
%token PROTECTED "protected"
%token PRIVATE "private"
%token LBRACE "{"
%token RBRACE "}"
%token LPAREN "("
%token RPAREN ")"
%token DOT "."
%token VOID "void"
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

%%
Program: %empty;
%%

int main () {
	yy::parser parser;
	return parser.parse();
}

void yyerror(const char* s) {
	cerr << "Parse error: " << s << " at line " << yylineno << '\n';
}

