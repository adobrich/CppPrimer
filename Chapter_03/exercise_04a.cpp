// Write a program to read two strings and report whether the strings
// are equal. If not, report which of the two is larger. Now, change
// the program to report whether the strings have the same length, and
// if not, report which is longer.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    cout << "Enter two strings to compare: ";
    string firstString;
    string secondString;
    if (cin >> firstString >> secondString)
    {
        if (firstString == secondString)
        {
            cout << "Strings are equal." << endl;
        }
        else
        {
            string result = "larger";
            if (firstString < secondString)
            {
                result = "smaller";
            }

            cout << "'" << firstString << "' is " << result
                 << " than '" << secondString << "'" << endl;
        }
    }
    else
    {
        std::cerr << endl << "Please enter two strings." << endl;

        return -1;

    }

    return 0;
}
