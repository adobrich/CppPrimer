// Write your own versions of the `fact.cc` and `factMain.cc` files.
// These files should include your `Chapter6.h` from the exercises in
// the previous section. Use these files to understand how your compiler
// supports separate compilation.

#include<iostream>
#include "../include/Chapter6.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Factorial" << endl
         << "Enter an integer: ";
    int userInput;
    cin >> userInput;

    cout << userInput << "! = " << fact(userInput) << endl;

    return 0;
}
