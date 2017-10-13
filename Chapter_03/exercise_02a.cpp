// Write a program to read the standard input a line at a time.
// Modify your program to read a word at a time

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string userInput;
    while (getline(cin, userInput))
    {
        if (!userInput.empty())
        {
            cout << userInput << endl;
        }
    }

    return 0;
}
