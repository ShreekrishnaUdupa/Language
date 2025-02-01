#include <fstream>
#include "interpreter.hpp"

using std::ifstream;
using std::ofstream;

int main ( int argc, const char* argv[] ) {

/*
    if (argc < 2)
    {
        cerr << "\033[31mArgumentsError: Too few arguments for the program.\033[0m";
        exit(1);
    }

    if (argc > 2)
    {
        cerr << "\033[31mArgumentsError: Too many arguments for the program.\033[0m";
        exit(1);
    }
*/
    string sourceCode;
    vector<Token> tokens;

    {
        ifstream fin;
        fin.open("File.anial");

        string temp;

        while (!fin.eof())
        {
            getline(fin, temp);
            sourceCode += temp;
        }

        fin.close();
    }

    cout << sourceCode;
    
    {
        Lexer lexer(sourceCode);
        tokens = lexer.tokens;
    }

    {
        Parser parser (tokens);
    }
    
    return 0;
}