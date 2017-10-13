// Write a program to read strings from standard input
// looking for duplicated words. The program should find places in the input
// where one word is followed immediately by itself. Keep track of the largest
// number of times a single repetition occurs and which word is repeated. Print
// the maximum number of duplicates, or else print a message saying that no
// word was repeated. For example, if the input is
// `how now now now brown cow cow`
// the output should indicate that the word `now` occurred three times.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string maxWord = "";
    int maxCount = 0;
    string previousWord = "";
    int currentCount = 0;
    string userInput;

    while (cin >> userInput)
    {
        if (userInput == previousWord)
        {
            ++currentCount;
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                maxWord = userInput;
            }
        }
        else
        {
            currentCount = 1;
        }
        previousWord = userInput;
    }
    if (maxCount < 2)
    {
        cout << "No matching consecutive words!" << endl;
    }
    else
    {
        cout << "'" << maxWord << "' occurred "
             << maxCount << " times." << endl;
    }

    return 0;
}
