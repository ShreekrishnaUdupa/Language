#include "interpreter.hpp"

int main ( int argc, const char* argv[] )
{
    // if (argc < 2)
    // {
    //     cerr << "ArgumentsError: Too few arguments for the program!";
    //     exit(1);
    // }

    // if (argc > 2)
    // {
    //     cerr << "ArgumentsError: Too many arguments for the program!";
    //     exit(1);
    // }

    string s = "class File {\n\tvoid main () {\n\t\tConsole.print(\"Hello World\");\n\t\tInt i = 287;\n\t}\n}";

    Lexer lexer(s);

    const auto tokens = lexer.tokens;

    for (const auto& value: tokens)
        cout << value.type << ':' << value.value << '\n';

    return 0;
}