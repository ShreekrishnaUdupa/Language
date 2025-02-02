#include <fstream>
#include "interpreter.hpp"

using std::ifstream;
using std::ofstream;

int main ( int argc, const char* args[] ) {
    
    string sourceCode;
    vector<Token> tokens;

    // Hint: You can also dynamically allocate the above variables in the heap to save up space (do it later)

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

    {
        Lexer lexer(sourceCode);
        tokens = lexer.tokens;
    }

    {
        Parser parser(tokens);
    }
    
    return 0;
}