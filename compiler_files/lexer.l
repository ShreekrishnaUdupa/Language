%option c++
%option yylineno
%option nounput
%option noyywrap

%{
    #define yyFlexLexer MyFlexLexer
    #include <FlexLexer.h>
    #include <iostream>
    using namespace std;
%}

IDENT [a-zA-Z_][a-zA-Z0-9_]*

%%

{IDENT} {
    if (string(yytext) == "Main")
        cout << "Main found\n";
    else
        cout << "Identifier: " << yytext << '\n';
}

. {
    cout << "Unexpected character: " << yytext << '\n';
}

%%

// ✅ define the missing method explicitly
int MyFlexLexer::yywrap() {
    return 1;
}
