// Rewrite the program in the first exercise, first using a while and
// again using a traditional for loop. Which of the three aproaches do
// you prefer and why?

// Rewrite of Exercise 3.6 using a while loop

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
        decltype(userInput.size()) index = 0;
        while (index < userInput.size())
        {
            userInput[index] = 'X';
            ++index;
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
