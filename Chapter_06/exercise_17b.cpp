// Write a function to determine whether a `string` contains any capital letters.
// Write a function to change a `string` to all lowercase. Do the parameters you
// used in these functions have the same type? If so, why? If not, why not?

// Function to change a string to lower case

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void toLower(string& s)
{
    for (auto& letter : s)
    {
        letter = tolower(letter);
    }
}

int main()
{
    cout << "Enter some text: ";
    string userInput;
    getline(cin, userInput);
    toLower(userInput);
    cout << "Converted text: "
         << userInput << endl;

    return 0;
}
