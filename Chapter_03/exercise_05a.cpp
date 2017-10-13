// Write a program to read strings from the standard input,
// concatenating what is read into one large string. Print the
// concatenated string. Next, change the program to separate
// adjacent input strings by a space.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    cout << "Enter some text: ";
    string userInput;
    if (cin >> userInput)
    {
        string combinedInput = userInput;
        while (cin >> userInput)
        {
            combinedInput += userInput;
        }
        cout << combinedInput << endl;
    }
    else
    {
        std::cerr << endl << "No input to concatenate!" << endl;

        return -1;

    }

    return 0;
}
