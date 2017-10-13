// Write a program to read a sequence of strings from the standard input
// until the same word occurs twice in succession or all the words have
// been read. Use a `while` loop to read the text one word at a time.
// Use the `break` statement to terminate the loop if a word occurs twice
// in succession. Print the word if it occurs twice in succession, or else
// print a message saying that no word was repeated.

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
        if (previousWord == userInput)
        {
            isRepeated = true;
            break;
        }
        previousWord = userInput;
    }

    if (isRepeated)
    {
        cout << "'" << previousWord << "' "
             << "occurred twice in a row." << endl;
    }
    else
    {
        cout << "No words were repeated in succession." << endl;
    }

    return 0;
}
