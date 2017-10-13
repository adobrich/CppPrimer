// Write a program to compare two strings. Now write a program to compare
// the values of two C-style character strings.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string firstString = "Hello";
    string secondString = "Helloo";

    if (firstString == secondString)
    {
        cout << "Strings match!" << endl;
    }
    else if (firstString > secondString)
    {
        cout << "'" << firstString << "' is greater than '"
             << secondString << "'" << endl;
    }
    else
    {
        cout << "'" << firstString << "' is less than '"
             << secondString << "'" << endl;
    }
    return 0;
}
