// Write a function to determine whether a `string` contains any capital letters.
// Write a function to change a `string` to all lowercase. Do the parameters you
// used in these functions have the same type? If so, why? If not, why not?

// Function to check if a string has upper case characters

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool hasUpperCase(const string& s)
{
    for (auto letter : s)
    {
        if (isupper(letter))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Enter some text: ";
    string userInput;
    getline(cin, userInput);
    cout << "The text you entered has "
         << (hasUpperCase(userInput) ? "" : "no ")
         << "upper case characters." << endl;

    return 0;
}
