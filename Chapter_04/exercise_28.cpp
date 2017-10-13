// Write a program to print the size of each of the built-in types.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Size of nullptr:     " << sizeof(nullptr) << " byte(s)." << endl
         << "Size of bool:        " << sizeof(bool) << " byte(s)." << endl
         << "Size of char:        " << sizeof(char) << " byte(s)." << endl
         << "Size of wchar_t:     " << sizeof(wchar_t) << " byte(s)." << endl
         << "Size of char16_t:    " << sizeof(char16_t) << " byte(s)." << endl
         << "Size of char32_t:    " << sizeof(char32_t) << " byte(s)." << endl
         << "Size of short:       " << sizeof(short) << " byte(s)." << endl
         << "Size of int:         " << sizeof(int) << " byte(s)." << endl
         << "Size of long:        " << sizeof(long) << " byte(s)." << endl
         << "Size of long long:   " << sizeof(long long) << " byte(s)." << endl
         << "Size of float:       " << sizeof(float) << " byte(s)." << endl
         << "Size of double:      " << sizeof(double) << " byte(s)." << endl
         << "Size of long double: " << sizeof(long double) << " byte(s)." << endl;

    return 0;
}
