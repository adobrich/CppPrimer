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
        for (auto& character : userInput)
        {
            character = 'X';
        }
    }
    else
    {
        cerr << endl << "No text entered!" << endl;

        return -1;
    }

    cout << "Converted text: " << userInput << endl;

    return 0;
}
