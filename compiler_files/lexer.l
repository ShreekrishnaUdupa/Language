%option c++
%option noyywrap nodefault

%{
#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;
using namespace yy;

int yyFlexLexer::yylex () {
    return 0;
}

#define YY_DECL yy::parser::symbol_type Lexer::scan ()
%}

%%
"class"         { return parser::make_CLASS (); }
"Main"          { return parser::make_TOKEN_Main (); }
"main"          { return parser::make_TOKEN_main (); }
"void"          { return parser::make_VOID (); }
"return"        { return parser::make_RETURN (); }
"public"        { return parser::make_PUBLIC (); }
"private"       { return parser::make_PRIVATE (); }
"protected"     { return parser::make_PROTECTED (); }
"{"             { return parser::make_LBRACE (); }
"}"             { return parser::make_RBRACE (); }
"("             { return parser::make_LPAREN (); }
")"             { return parser::make_RPAREN (); }

"++"            { return parser::make_INCREMENT (); }
"--"            { return parser::make_DECREMENT (); }
"||"            { return parser::make_LOGICAL_OR (); }
"&&"            { return parser::make_LOGICAL_AND (); }
">="            { return parser::make_GE (); }
"<="            { return parser::make_LE (); }
"!="            { return parser::make_NE (); }
"=="            { return parser::make_E (); }
"+="            { return parser::make_PLUS_ASSIGNMENT (); }
"-="            { return parser::make_MINUS_ASSIGNMENT (); }
"*="            { return parser::make_MULTIPLY_ASSIGNMENT (); }
"/="            { return parser::make_DIVIDE_ASSIGNMENT (); }
"%="            { return parser::make_MODULO_ASSIGNMENT (); }
"|="            { return parser::make_BIT_OR_ASSIGNMENT (); }
"&="            { return parser::make_BIT_AND_ASSIGNMENT (); }
"^="            { return parser::make_BIT_XOR_ASSIGNMENT (); }
"<<="           { return parser::make_LEFT_SHIFT_ASSIGNMENT (); }
">>="           { return parser::make_RIGHT_SHIFT_ASSIGNMENT (); }
"<<"            { return parser::make_LEFT_SHIFT (); }
">>"            { return parser::make_RIGHT_SHIFT (); }

"*"             { return parser::make_MULTIPLY (); }
"/"             { return parser::make_DIVIDE (); }
"%"             { return parser::make_MODULO (); }
"="             { return parser::make_ASSIGNMENT (); }
">"             { return parser::make_GREATER (); }
"<"             { return parser::make_LESSER (); }
"!"             { return parser::make_LOGICAL_NOT (); }
"&"             { return parser::make_BIT_AND (); }
"|"             { return parser::make_BIT_OR (); }
"^"             { return parser::make_BIT_XOR (); }
"~"             { return parser::make_BIT_NOT (); }
";"             { return parser::make_SEMICOLON (); }
","             { return parser::make_COMMA (); }

[+-]?([0-9]+\.[0-9]+|\.[0-9]+)([eE][+-]?[0-9]+)?    { return parser::make_FLOATING_LITERAL (stod(yytext)); }
[+-]?[0-9]+([eE][+-]?[0-9]+)?                       { return parser::make_INTEGER_LITERAL (stoi(yytext)); }

[a-zA-Z_][a-zA-Z0-9_]*                              { return parser::make_IDENTIFIER (yytext); }
\"([^"\\]|\\.)*\"                                   { return parser::make_STRING_LITERAL (yytext); }

\/\*([^*]|\*+[^*/])*\*+\/       {}
\/\/[^\n]*                      {} 
[ \n\t\r]+                      {}

"."             { return parser::make_DOT (); }
"+"             { return parser::make_PLUS (); }
"-"             { return parser::make_MINUS (); }

.               { return parser::make_UNKNOWN (); }
<<EOF>>         { return parser::make_YYEOF (); }
%%

/* yyleng: returns the length of the string matched */