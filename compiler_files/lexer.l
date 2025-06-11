%option c++
%option noyywrap

%{
#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;
using token = yy::parser::token;
%}

%%
"class"         { return token::CLASS; }
"Main"          { return token::TOKEN_Main; }
"main"          { return token::TOKEN_main; }
"void"          { return token::VOID; }
"return"        { return token::RETURN; }
"public"        { return token::PUBLIC; }
"private"       { return token::PRIVATE; }
"protected"     { return token::PROTECTED; }
"{"             { return token::LBRACE; }
"}"             { return token::RBRACE; }
"("             { return token::LPAREN; }
")"             { return token::RPAREN; }

"++"            { return token::INCREMENT; }
"--"            { return token::DECREMENT; }
"||"            { return token::LOGICAL_OR; }
"&&"            { return token::LOGICAL_AND; }
">="            { return token::GE; }
"<="            { return token::LE; }
"!="            { return token::NE; }
"=="            { return token::E; }
"+="            { return token::PLUS_ASSIGNMENT; }
"-="            { return token::MINUS_ASSIGNMENT; }
"*="            { return token::MULTIPLY_ASSIGNMENT; }
"/="            { return token::DIVIDE_ASSIGNMENT; }
"%="            { return token::MODULO_ASSIGNMENT; }
"|="            { return token::BIT_OR_ASSIGNMENT; }
"&="            { return token::BIT_AND_ASSIGNMENT; }
"^="            { return token::BIT_XOR_ASSIGNMENT; }
"<<="           { return token::LEFT_SHIFT_ASSIGNMENT; }
">>="           { return token::RIGHT_SHIFT_ASSIGNMENT; }
"<<"            { return token::LEFT_SHIFT; }
">>"            { return token::RIGHT_SHIFT; }

"*"             { return token::MULTIPLY; }
"/"             { return token::DIVIDE; }
"%"             { return token::MODULO; }
"="             { return token::ASSIGNMENT; }
">"             { return token::GREATER; }
"<"             { return token::LESSER; }
"!"             { return token::LOGICAL_NOT; }
"&"             { return token::BIT_AND; }
"|"             { return token::BIT_OR; }
"^"             { return token::BIT_XOR; }
"~"             { return token::BIT_NOT; }
";"             { return token::SEMICOLON; }
","             { return token::COMMA; }

[+-]?([0-9]+\.[0-9]+|\.[0-9]+)([eE][+-]?[0-9]+)?    { return token::FLOATING_LITERAL; }
[+-]?[0-9]+([eE][+-]?[0-9]+)?                       { return token::INTEGER_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]*                              { return token::IDENTIFIER; }
\"([^"\\]|\\.)*\"                                   { return token::STRING_LITERAL; }

\/\*([^*]|\*+[^*/])*\*+\/       {} 
\/\/[^\n]*                      {} 
[ \n\t\r]+                      {}

"."             { return token::DOT; }
"+"             { return token::PLUS; }
"-"             { return token::MINUS; }

.               { return token::UNKNOWN; }
<<EOF>>         { return token::YYEOF; }
%%

/* yyleng: returns the length of the string matched */