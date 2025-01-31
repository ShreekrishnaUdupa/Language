#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

class Lexer {
private:

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

            if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
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
};

#endif