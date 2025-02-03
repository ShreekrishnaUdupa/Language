#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::to_string;

class Int {
public:
    int value;

    Int (int value) {
        this->value = value;
    }
};

class Bool {
public:
    bool value;

    Bool (bool value) {
        this->value = value;
    }
};

class Console {
private:

    string hexToNum (const char a, const char b)
    {
        string s;
        short int value;

        if ( a >= '0' && a <= '9' )
            value = 16 * (a - 48);

        else {
            switch (a)
            {
                case 'a': value = 160; break;
                case 'b': value = 176; break;
                case 'c': value = 192; break;
                case 'd': value = 208; break;
                case 'e': value = 224; break;
                case 'f': value = 240; break;

                case 'A': value = 160; break;
                case 'B': value = 176; break;
                case 'C': value = 192; break;
                case 'D': value = 208; break;
                case 'E': value = 224; break;
                case 'F': value = 240; break;

                default:
                    cerr << "\033Error: Invalid Hexcode.\033[0m";
                    exit(1);
            }
        }

        if ( b >= '0' && b <= '9' )
            value += b - 48;

        else {
            switch (b)
            {
                case 'a': value += 10; break;
                case 'b': value += 11; break;
                case 'c': value += 12; break;
                case 'd': value += 13; break;
                case 'e': value += 14; break;
                case 'f': value += 15; break;

                case 'A': value += 10; break;
                case 'B': value += 11; break;
                case 'C': value += 12; break;
                case 'D': value += 13; break;
                case 'E': value += 14; break;
                case 'F': value += 15; break;

                default:
                    cerr << "\033Error: Invalid hexcode.\033[0m";
                    exit(1);
            }
        }

        s = to_string(value);

        return s;
    }

    string escapeCode (const string& hexCode)
    {
        string s = "\033[38;2;";

        if (hexCode.size() != 7)
        {
            cerr << "\033Error: Invalid HexCode\033[0m";
            exit(1);
        }

        if (hexCode[0] != '#')
        {
            cerr << "\033Error: Invalid HexCode\033[0m";
            exit(1);
        }

        s += hexToNum (hexCode[1], hexCode[2]) + ';';
        s += hexToNum (hexCode[3], hexCode[4]) + ';';
        s += hexToNum (hexCode[5], hexCode[6]) + 'm';

        return s;
    }

public:
    inline void print (const char* s) {
        cout << s;
    }

    inline void println (const char* s) {
        cout << s << '\n';
    }

    inline void print (const char* s, string hexCode)
    {
        string str = escapeCode(hexCode) + s + "\033[0m";
        cout << str;
    }

    inline void println (const char* s, string hexCode)
    {
        string str = escapeCode(hexCode) + s + "\033[0m";
        cout << str << '\n';
    }

    inline void print (const Int& a) {
        cout << a.value;
    }

    inline void print (const Bool& a)
    {
        if (a.value == true) cout << "true";
        else cout << "false";
    }
};

Int operator + (const Int& a, const Int& b) { return Int(a.value + b.value); }
Int operator - (const Int& a, const Int& b) { return Int(a.value - b.value); }
Int operator * (const Int& a, const Int& b) { return Int(a.value * b.value); }
Int operator / (const Int& a, const Int& b) { return Int(a.value / b.value); }
Int operator % (const Int& a, const Int& b) { return Int(a.value % b.value); }

Bool operator + (const Bool& a, const Bool& b) { return Bool(a.value + b.value); }
Bool operator - (const Bool& a, const Bool& b) { return Bool(a.value - b.value); }
Bool operator * (const Bool& a, const Bool& b) { return Bool(a.value * b.value); }
Bool operator / (const Bool& a, const Bool& b) { return Bool(a.value / b.value); }
Bool operator % (const Bool& a, const Bool& b) { return Bool(a.value % b.value); }

Int operator + (const Int& a, const Bool& b) { return Int(a.value + b.value); }
Int operator - (const Int& a, const Bool& b) { return Int(a.value - b.value); }
Int operator * (const Int& a, const Bool& b) { return Int(a.value * b.value); }
Int operator / (const Int& a, const Bool& b) { return Int(a.value / b.value); }
Int operator % (const Int& a, const Bool& b) { return Int(a.value % b.value); }

template <typename T> Int operator + (const T& value, const Int& a) { return Int(value + a.value); }
template <typename T> Int operator + (const T& value, const Int& a) { return Int(value + a.value); }
template <typename T> Int operator + (const T& value, const Int& a) { return Int(value + a.value); }
template <typename T> Int operator + (const T& value, const Int& a) { return Int(value + a.value); }
template <typename T> Int operator + (const T& value, const Int& a) { return Int(value + a.value); }

int main ()
{
    Console console;

    console.print("This should be in some random color", "#11111");
    return 0;
}