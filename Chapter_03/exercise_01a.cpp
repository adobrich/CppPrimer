// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of exercise 1.9

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    int val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    cout << "The sum of the numbers from 50 to 100 inclusive is: "
         << sum << endl;

    return 0;
}
