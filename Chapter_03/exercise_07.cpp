// Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

int main()
{
    cout << "Enter text to convert: ";
    string userInput;
    if (cin >> userInput)
    {
        for (char character : userInput)
        {
            // character is now a local variable making any
            // change here will do nothing to userInput. The
            // compiler will warn of an unused variable since we've
            // set the value 'X' but never used character in the
            // program.
            character = 'X';
        }
    }
    else
    {
        cerr << endl << "No text entered!" << endl;

        return -1;
    }

    cout << "Not-so-converted text: " << userInput << endl;

    return 0;
}
