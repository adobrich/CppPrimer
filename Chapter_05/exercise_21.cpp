// Revise the program from the exercise in § 5.5.1 (p. 191) so that it
// looks only for duplicated words that start with an uppercase letter.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string userInput;
    string previousWord = "";
    bool isRepeated = false;

    while (cin >> userInput)
    {
        if (!isupper(userInput[0]))
        {
            previousWord = userInput;
            continue;
        }
        if (previousWord == userInput)
        {
            isRepeated = true;
            break;
        }
        else
        {
            previousWord = userInput;
        }

        // Commented code would probably be a better solution
        // but since this topic is on the `continue` statement
        // we'll use that instead.
        //
        // if (isupper(userInput[0]) && previousWord == userInput)
        // {
        //     isRepeated = true;
        //     break;
        // }
        // else
        // {
        //     previousWord = userInput;
        // }

    }
    if (isRepeated)
    {
        cout << "'" << previousWord << "' "
             << "occurred twice in a row." << endl;
    }
    else
    {
        cout << "No words with capitalised first letters were repeated in succession."
             << endl;
    }

    return 0;
}
