// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of exercise 1.11

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Enter a two number range (from low to high): ";
    int lowerBound = 0;
    int upperBound = 0;

    cin >> lowerBound >> upperBound;
    if (lowerBound < upperBound)
    {
        while (lowerBound <= upperBound)
        {
            cout << lowerBound << endl;
            ++lowerBound;
        }
    }

    return 0;
}
