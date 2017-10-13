// Write a program that reads a string of characters including punctuation
// and writes what was read but with the punctuation removed.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

int main()
{
    cout << "Enter text with punctuation: ";
    string userInput;
    if (cin >> userInput)
    {
        string cleanOutput;
        for (auto character : userInput)
        {
            if (!ispunct(character))
            {
                cleanOutput += character;
            }
        }
        cout << "Punctuation has been stripped: " << cleanOutput << endl;

        return 0;
    }
    else
    {
        cerr << endl << "No text entered!" << endl;

        return -1;
    }
}
