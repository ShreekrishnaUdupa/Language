#include <fstream>
#include "interpreter.hpp"

using std::ifstream;
using std::ofstream;

int main ( int argc, const char* args[] ) {

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

    // Hint: You can also dynamically allocate the above variables in the heap to save up space (do it later)

    {
        ifstream fin;
        fin.open("File.anial");

        if (!fin)
        {
            cerr << "\033[31mFileError: could not be opened or doesn't exist.\033[0m";
            exit(1);
        }

        string temp;

        while (!fin.eof())
        {
            getline(fin, temp);
            sourceCode += temp;
        }

        fin.close();
    }

    {
        Lexer lexer(sourceCode);
        tokens = lexer.tokens;
    }

    {
        Parser parser(tokens);
    }
    
    return 0;
}