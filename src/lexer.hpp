#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    LITERAL,
    DOT,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAREN,
    CLOSE_PAREN,
    SEMICOLON,
    ASSIGNMENT,
    UNKNOWN
};

using enum TokenType;

struct Token {
    TokenType type;
    string value;
};

class Lexer {
private:

    vector<string> program;
    vector<Token> tokens;

    vector<string> split (string s)
    {
        vector<string> program;
        string temp = "";
        short int doubleQuotes = 0;
        bool quotesActivated = false;

        for ( int i = 0; i < s.size(); ++i )
        {
            if (s[i] == '"')
            {
                if (doubleQuotes == 0)
                {
                    temp += '"';
                    doubleQuotes = 1;
                    quotesActivated = true;
                }

                else if (doubleQuotes == 1)
                {
                    temp += '"';
                    program.push_back(temp);
                    temp = "";
                    doubleQuotes = 0;
                    quotesActivated = false;
                }

                continue;
            }

            if (quotesActivated)
            {
                temp += s[i];
                continue;
            }

            switch (s[i])
            {
                case '.':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back(".");
                    temp = "";
                    continue;

                case ';':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back(";");
                    temp = "";
                    continue;

                case '{':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("{");
                    temp = "";
                    continue;

                case '}':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("}");
                    temp = "";
                    continue;

                case '(':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("(");
                    temp = "";
                    continue;

                case ')':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back(")");
                    temp = "";
                    continue;

                case '=':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("=");
                    temp = "";
                    continue;

                case '+':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("+");
                    temp = "";
                    continue;

                case '-':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("-");
                    temp = "";
                    continue;

                case '*':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("*");
                    temp = "";
                    continue;

                case '/':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("/");
                    temp = "";
                    continue;

                case '%':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("%");
                    temp = "";
                    continue;           
            }

            if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                temp += s[i];
                continue;
            }

            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            {
                if (temp != "")
                {
                    program.push_back(temp);
                    temp = "";
                }

                continue;
            }
        }

        return program;
    }

    vector<Token> addTokens (vector<string> program)
    {
        vector<Token> tokens;

        for (const string& value: program)
        {
            if (value == ".") tokens.push_back({DOT, "."});

            else if (value == ";") tokens.push_back({SEMICOLON, ";"});
            else if (value == "{") tokens.push_back({OPEN_BRACE, "{"});
            else if (value == "}") tokens.push_back({CLOSE_BRACE, "}"});
            else if (value == "(") tokens.push_back({OPEN_PAREN, "("});
            else if (value == ")") tokens.push_back({CLOSE_PAREN, ")"});
            else if (value == "=") tokens.push_back({ASSIGNMENT, "="});

            // Operators

            else if (value == "+") tokens.push_back({OPERATOR, "+"});
            else if (value == "-") tokens.push_back({OPERATOR, "-"});
            else if (value == "*") tokens.push_back({OPERATOR, "*"});
            else if (value == "/") tokens.push_back({OPERATOR, "/"});
            else if (value == "%") tokens.push_back({OPERATOR, "%"});


            else if (value[0] == '"') tokens.push_back({LITERAL, value});

            else if (value == "class" || value == "main" || value == "Int" || value == "main")
                tokens.push_back({KEYWORD, value});

            else tokens.push_back({IDENTIFIER, value});
        }

        return tokens;
    }

public:

    Lexer (string s)
    {
        program = split(s);
        tokens = addTokens(program);
    }
};

#endif