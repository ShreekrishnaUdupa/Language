// #include <iostream>
// #include <string>
// #include <concepts>

// using std::cin;
// using std::cout;
// using std::cerr;
// using std::string;
// using std::to_string;
// using std::is_same_v;

// class Int {
// public:
//     int32_t value;

//     Int (int value) {
//         this->value = value;
//     }
// };

// class Bool {
// public:
//     bool value;

//     Bool (bool value) {
//         this->value = value;
//     }
// };

// class Console {
// private:

//     string hexToNum (const char a, const char b)
//     {
//         string s;
//         short int value;

//         if ( a >= '0' && a <= '9' )
//             value = 16 * (a - 48);

//         else {
//             switch (a)
//             {
//                 case 'a': value = 160; break;
//                 case 'b': value = 176; break;
//                 case 'c': value = 192; break;
//                 case 'd': value = 208; break;
//                 case 'e': value = 224; break;
//                 case 'f': value = 240; break;

//                 case 'A': value = 160; break;
//                 case 'B': value = 176; break;
//                 case 'C': value = 192; break;
//                 case 'D': value = 208; break;
//                 case 'E': value = 224; break;
//                 case 'F': value = 240; break;

//                 default:
//                     cerr << "\033[31mError: Invalid Hexcode.\033[0m";
//                     exit(1);
//             }
//         }

//         if ( b >= '0' && b <= '9' )
//             value += b - 48;

//         else {
//             switch (b)
//             {
//                 case 'a': value += 10; break;
//                 case 'b': value += 11; break;
//                 case 'c': value += 12; break;
//                 case 'd': value += 13; break;
//                 case 'e': value += 14; break;
//                 case 'f': value += 15; break;

//                 case 'A': value += 10; break;
//                 case 'B': value += 11; break;
//                 case 'C': value += 12; break;
//                 case 'D': value += 13; break;
//                 case 'E': value += 14; break;
//                 case 'F': value += 15; break;

//                 default:
//                     cerr << "\033[31mError: Invalid hexcode.\033[0m";
//                     exit(1);
//             }
//         }

//         s = to_string(value);

//         return s;
//     }

//     string escapeCode (const string& hexCode)
//     {
//         string s = "\033[38;2;";

//         if (hexCode.size() != 7)
//         {
//             cerr << "\033[31mError: Invalid HexCode\033[0m";
//             exit(1);
//         }

//         if (hexCode[0] != '#')
//         {
//             cerr << "\033[31mError: Invalid HexCode\033[0m";
//             exit(1);
//         }

//         s += hexToNum (hexCode[1], hexCode[2]) + ';';
//         s += hexToNum (hexCode[3], hexCode[4]) + ';';
//         s += hexToNum (hexCode[5], hexCode[6]) + 'm';

//         return s;
//     }

// public:
//     inline void print (const char* s) {
//         cout << s;
//     }

//     inline void println (const char* s) {
//         cout << s << '\n';
//     }

//     inline void print (const char* s, string hexCode) {
//         cout << escapeCode(hexCode) + s + "\033[0m";
//     }

//     inline void println (const char* s, string hexCode) {
//         cout << escapeCode(hexCode) + s + "\033[0m";
//     }

//     inline void print (const Int& a) {
//         cout << a.value;
//     }

//     inline void print (const Bool& a) {

//         if (a.value == true)
//             cout << "true";

//         else
//             cout << "false";
//     }
// };

// template <typename T>
// concept AllowedClass = is_same_v<T, Int> || is_same_v<T, Bool>;

// template <AllowedClass T, AllowedClass U>
// Int operator + (const T& a, const U& b) { return Int(a.value + b.value); }

// template <AllowedClass T, AllowedClass U>
// Int operator - (const T& a, const U& b) { return Int(a.value - b.value); }

// template <AllowedClass T, AllowedClass U>
// Int operator * (const T& a, const U& b) { return Int(a.value * b.value); }

// template <AllowedClass T, AllowedClass U>
// Int operator / (const T& a, const U& b) { return Int(a.value / b.value); }

// template <AllowedClass T, AllowedClass U>
// Int operator % (const T& a, const U& b) { return Int(a.value % b.value); }

// int main ()
// {
//     // Console console;

//     // console.print("This should be in some random color", "#111111");
//     return 0;
// }


class Int {
public:
    int value;

    Int (int value) {
        this->value = value;
    }
};

int main () {
    Int x(42);
    return 0;
}