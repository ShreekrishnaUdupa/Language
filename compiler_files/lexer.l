%option c++
%option noyywrap noinput nounput batch debug

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
"class"         { update_loc (); return parser::make_CLASS (yylloc); }
"return"        { update_loc (); return parser::make_RETURN (yylloc); }
"public"        { update_loc (); return parser::make_PUBLIC (yylloc); }
"private"       { update_loc (); return parser::make_PRIVATE (yylloc); }
"protected"     { update_loc (); return parser::make_PROTECTED (yylloc); }
"constructor"   { update_loc (); return parser::make_CONSTRUCTOR (yylloc); }
"destructor"    { update_loc (); return parser::make_DESTRUCTOR (yylloc); }

"++"            { update_loc (); return parser::make_INCREMENT (yylloc); }
"--"            { update_loc (); return parser::make_DECREMENT (yylloc); }
"||"            { update_loc (); return parser::make_LOGICAL_OR (yylloc); }
"&&"            { update_loc (); return parser::make_LOGICAL_AND (yylloc); }
">="            { update_loc (); return parser::make_GE (yylloc); }
"<="            { update_loc (); return parser::make_LE (yylloc); }
"!="            { update_loc (); return parser::make_NE (yylloc); }
"=="            { update_loc (); return parser::make_E (yylloc); }
"+="            { update_loc (); return parser::make_PLUS_ASSIGNMENT (yylloc); }
"-="            { update_loc (); return parser::make_MINUS_ASSIGNMENT (yylloc); }
"*="            { update_loc (); return parser::make_MULTIPLY_ASSIGNMENT (yylloc); }
"/="            { update_loc (); return parser::make_DIVIDE_ASSIGNMENT (yylloc); }
"%="            { update_loc (); return parser::make_MODULO_ASSIGNMENT (yylloc); }
"|="            { update_loc (); return parser::make_BIT_OR_ASSIGNMENT (yylloc); }
"&="            { update_loc (); return parser::make_BIT_AND_ASSIGNMENT (yylloc); }
"^="            { update_loc (); return parser::make_BIT_XOR_ASSIGNMENT (yylloc); }
"<<="           { update_loc (); return parser::make_LEFT_SHIFT_ASSIGNMENT (yylloc); }
">>="           { update_loc (); return parser::make_RIGHT_SHIFT_ASSIGNMENT (yylloc); }
"<<"            { update_loc (); return parser::make_LEFT_SHIFT (yylloc); }
">>"            { update_loc (); return parser::make_RIGHT_SHIFT (yylloc); }

[+-]?([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][+-]?[0-9]+)?  { update_loc (); return parser::make_FLOATING_LITERAL (stod(yytext), yylloc); }
[+-]?[0-9]+([eE][+-]?[0-9]+)?                           { update_loc (); return parser::make_INTEGER_LITERAL  (stoi(yytext), yylloc); }
`
[a-zA-Z_][a-zA-Z0-9_]*                                  { update_loc (); return parser::make_IDENTIFIER     (yytext, yylloc); }
\"([^"\\]|\\.)*\"                                       { update_loc (); return parser::make_STRING_LITERAL (yytext, yylloc); }

"\n"            { yylloc.begin.line = ++yylloc.end.line; yylloc.begin.column = yylloc.end.column = 1; }
[ \t]           { update_loc (); }
\/\/[^\n]*      {}

\/\*([^*]|\*+[^*/])*\*+\/ {
    const string& s = yytext;

    for (const char& c: s)
    {
        if (c == '\n')
            yylloc.begin.line = ++yylloc.end.line,
            yylloc.begin.column = yylloc.end.column = 1;

        else
            yylloc.begin.column = ++yylloc.end.column;
    }}

"{"             { update_loc (); return parser::make_LBRACE (yylloc); }
"}"             { update_loc (); return parser::make_RBRACE (yylloc); }
"("             { update_loc (); return parser::make_LPAREN (yylloc); }
")"             { update_loc (); return parser::make_RPAREN (yylloc); }
"*"             { update_loc (); return parser::make_MULTIPLY (yylloc); }
"/"             { update_loc (); return parser::make_DIVIDE (yylloc); }
"%"             { update_loc (); return parser::make_MODULO (yylloc); }
"+"             { update_loc (); return parser::make_PLUS (yylloc); }
"-"             { update_loc (); return parser::make_MINUS (yylloc); }
"="             { update_loc (); return parser::make_ASSIGNMENT (yylloc); }
">"             { update_loc (); return parser::make_GREATER (yylloc); }
"<"             { update_loc (); return parser::make_LESSER (yylloc); }
"!"             { update_loc (); return parser::make_LOGICAL_NOT (yylloc); }
"&"             { update_loc (); return parser::make_BIT_AND (yylloc); }
"|"             { update_loc (); return parser::make_BIT_OR (yylloc); }
"^"             { update_loc (); return parser::make_BIT_XOR (yylloc); }
"~"             { update_loc (); return parser::make_BIT_NOT (yylloc); }
";"             { update_loc (); return parser::make_SEMICOLON (yylloc); }
","             { update_loc (); return parser::make_COMMA (yylloc); }
"."             { update_loc (); return parser::make_DOT (yylloc); }
":"             { update_loc (); return parser::make_COLON (yylloc); }

.               { update_loc (); return parser::make_UNKNOWN (yylloc); }
<<EOF>>         { update_loc (); return parser::make_YYEOF (yylloc); }
%%