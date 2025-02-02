#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::cerr;
using std::vector;
using std::string;

enum TokenType {
    keyword,
    identifier,
    op,
    literal,
    dot,
    open_brace,
    close_brace,
    open_paren,
    close_paren,
    semicolon,
    assignment,
    unknown
};

using enum TokenType;

struct Token {
    TokenType type;
    string value;
};

class Lexer {
private:

    vector<string> split (const string& s) {

        vector<string> program;
        string temp;
        short int doubleQuotes = 0;
        bool quotesActivated = false;

        for ( int i = 0; i < s.size(); ++i ) {
            
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
                    temp.clear();
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
                    temp.clear();
                    break;

                case ';':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back(";");
                    temp.clear();
                    break;

                case '{':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("{");
                    temp.clear();
                    break;

                case '}':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("}");
                    temp.clear();
                    break;

                case '(':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("(");
                    temp.clear();
                    break;

                case ')':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back(")");
                    temp.clear();
                    break;

                case '=':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("=");
                    temp.clear();
                    break;

                case '+':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("+");
                    temp.clear();
                    break;

                case '-':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("-");
                    temp.clear();
                    break;

                case '*':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("*");
                    temp.clear();
                    break;

                case '/':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("/");
                    temp.clear();
                    break;

                case '%':
                    if (temp != "")
                        program.push_back(temp);

                    program.push_back("%");
                    temp.clear();
                    break;           
            }

            if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_' )
            {
                temp += s[i];
                continue;
            }

            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            {
                if (temp != "")
                {
                    program.push_back(temp);
                    temp.clear();
                }

                continue;
            }
        }

        return program;
    }

    void validateTokens (const vector<Token>& tokens) {

        for (const auto& value: tokens) {

            if (value.type == literal && value.value[0] >= '0' && value.value[0] <= '9')
            {
                for (const auto& num: value.value)
                {
                    if(!(num >= '0' && num <= '9'))
                    {
                        cerr << "\033[31mTokenError: Illegal Literal.\033[0m";
                        exit(1);
                    }
                }
            }
        }
    }

    vector<Token> addTokens (const vector<string>& program) {

        vector<Token> tokens;

        for (const string& value: program) {
            
            if (value == ".") tokens.push_back({dot, "."});

            else if (value == ";") tokens.push_back({semicolon, ";"});
            else if (value == "{") tokens.push_back({open_brace, "{"});
            else if (value == "}") tokens.push_back({close_brace, "}"});
            else if (value == "(") tokens.push_back({open_paren, "("});
            else if (value == ")") tokens.push_back({close_paren, ")"});
            else if (value == "=") tokens.push_back({assignment, "="});

            // Operators

            else if (value == "+") tokens.push_back({op, "+"});
            else if (value == "-") tokens.push_back({op, "-"});
            else if (value == "*") tokens.push_back({op, "*"});
            else if (value == "/") tokens.push_back({op, "/"});
            else if (value == "%") tokens.push_back({op, "%"});

            else if (value == "true" || value == "false")
                tokens.push_back({literal, value});

            else if (value == "class" || value == "void" || value == "main" || value == "Int" || value == "Bool")
                tokens.push_back({keyword, value});

            else if ( (value[0] >= 'a' && value[0] <= 'z') || (value[0] >= 'A' && value[0] <= 'Z') || value[0] == '_' )
                tokens.push_back({identifier, value});

            else if (value[0] >= '0' && value[0] <= '9')
                tokens.push_back({literal, value});

            else if (value[0] == '"')
                tokens.push_back({literal, value});
        }

        validateTokens(tokens);
        return tokens;
    }

public:
    vector<string> program;
    vector<Token> tokens;

    Lexer (const string& s)
    {
        program = split(s);
        tokens = addTokens(program);
    }
};

#endif