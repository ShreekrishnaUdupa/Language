%option c++
%option noyywrap noinput nounput batch debug

%{
#undef SIZE_MAX

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

floating_literal            [+-]?([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][+-]?[0-9]+)?
integer_literal             [+-]?[0-9]+([eE][+-]?[0-9]+)?
identifier                  [a-zA-Z_][a-zA-Z0-9_]*
string_literal              \"([^"\\]|\\.)*\"

single_line_comment         \/\/[^\n]*
multi_line_comment          \/\*([^*]|\*+[^*/])*\*+\/

%%
"class"                 { update_loc (); return parser::make_CLASS (yylloc); }
"return"                { update_loc (); return parser::make_RETURN (yylloc); }
"public"                { update_loc (); return parser::make_PUBLIC (yylloc); }
"private"               { update_loc (); return parser::make_PRIVATE (yylloc); }
"protected"             { update_loc (); return parser::make_PROTECTED (yylloc); }
"constructor"           { update_loc (); return parser::make_CONSTRUCTOR (yylloc); }
"destructor"            { update_loc (); return parser::make_DESTRUCTOR (yylloc); }
"if"                    { update_loc (); return parser::make_IF (yylloc); }
"else"                  { update_loc (); return parser::make_ELSE (yylloc); }

{floating_literal}      { update_loc (); return parser::make_FLOATING_LITERAL (stold (yytext), yylloc); }
{integer_literal}       { update_loc (); return parser::make_INTEGER_LITERAL  (stoll (yytext), yylloc); }
"true"                  { update_loc (); return parser::make_BOOLEAN_LITERAL  (true, yylloc); }
"false"                 { update_loc (); return parser::make_BOOLEAN_LITERAL  (false, yylloc); }

{identifier}            { update_loc (); return parser::make_IDENTIFIER     (yytext, yylloc); }
{string_literal}        { update_loc (); return parser::make_STRING_LITERAL (yytext, yylloc); }

[\n]                    { yylloc.begin.line = ++yylloc.end.line; yylloc.begin.column = yylloc.end.column = 1; }
[ \t]                   { update_loc (); }

{single_line_comment}   {}
{multi_line_comment}    { update_loc_mc (); }

"++"                    { update_loc (); return parser::make_INCREMENT (yylloc); }
"--"                    { update_loc (); return parser::make_DECREMENT (yylloc); }
"||"                    { update_loc (); return parser::make_LOGICAL_OR (yylloc); }
"&&"                    { update_loc (); return parser::make_LOGICAL_AND (yylloc); }
">="                    { update_loc (); return parser::make_GE (yylloc); }
"<="                    { update_loc (); return parser::make_LE (yylloc); }
"!="                    { update_loc (); return parser::make_NE (yylloc); }
"=="                    { update_loc (); return parser::make_E (yylloc); }
"+="                    { update_loc (); return parser::make_PLUS_ASSIGNMENT (yylloc); }
"-="                    { update_loc (); return parser::make_MINUS_ASSIGNMENT (yylloc); }
"*="                    { update_loc (); return parser::make_MULTIPLY_ASSIGNMENT (yylloc); }
"/="                    { update_loc (); return parser::make_DIVIDE_ASSIGNMENT (yylloc); }
"%="                    { update_loc (); return parser::make_MODULO_ASSIGNMENT (yylloc); }
"|="                    { update_loc (); return parser::make_BIT_OR_ASSIGNMENT (yylloc); }
"&="                    { update_loc (); return parser::make_BIT_AND_ASSIGNMENT (yylloc); }
"^="                    { update_loc (); return parser::make_BIT_XOR_ASSIGNMENT (yylloc); }
"<<="                   { update_loc (); return parser::make_LEFT_SHIFT_ASSIGNMENT (yylloc); }
">>="                   { update_loc (); return parser::make_RIGHT_SHIFT_ASSIGNMENT (yylloc); }
"<<"                    { update_loc (); return parser::make_LEFT_SHIFT (yylloc); }
">>"                    { update_loc (); return parser::make_RIGHT_SHIFT (yylloc); }

"{"                     { update_loc (); return parser::make_LBRACE (yylloc); }
"}"                     { update_loc (); return parser::make_RBRACE (yylloc); }
"("                     { update_loc (); return parser::make_LPAREN (yylloc); }
")"                     { update_loc (); return parser::make_RPAREN (yylloc); }
"*"                     { update_loc (); return parser::make_MULTIPLY (yylloc); }
"/"                     { update_loc (); return parser::make_DIVIDE (yylloc); }
"%"                     { update_loc (); return parser::make_MODULO (yylloc); }
"+"                     { update_loc (); return parser::make_PLUS (yylloc); }
"-"                     { update_loc (); return parser::make_MINUS (yylloc); }
"="                     { update_loc (); return parser::make_ASSIGNMENT (yylloc); }
">"                     { update_loc (); return parser::make_GREATER (yylloc); }
"<"                     { update_loc (); return parser::make_LESSER (yylloc); }
"!"                     { update_loc (); return parser::make_LOGICAL_NOT (yylloc); }
"&"                     { update_loc (); return parser::make_BIT_AND (yylloc); }
"|"                     { update_loc (); return parser::make_BIT_OR (yylloc); }
"^"                     { update_loc (); return parser::make_BIT_XOR (yylloc); }
"~"                     { update_loc (); return parser::make_BIT_NOT (yylloc); }
";"                     { update_loc (); return parser::make_SEMICOLON (yylloc); }
","                     { update_loc (); return parser::make_COMMA (yylloc); }
"."                     { update_loc (); return parser::make_DOT (yylloc); }
":"                     { update_loc (); return parser::make_COLON (yylloc); }

.                       { update_loc (); return parser::make_UNKNOWN (yylloc); }
<<EOF>>                 { update_loc (); return parser::make_YYEOF (yylloc); }
%%