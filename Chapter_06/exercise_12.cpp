// Rewrite the program from [exercise 6.10](exercise_10.cpp) in § 6.2.1 (p. 210)
// to use references instead of pointers to swap the value of two ints. Which
// version do you think would be eaisier to use and why?

#include <iostream>

using std::cout;
using std::endl;

void swapValues(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int firstValue = 21;
    int secondValue = 43;

    cout << "Starting values:" << endl
         << "First value =\t" << firstValue << endl
         << "Second value =\t" << secondValue << endl;

    swapValues(firstValue, secondValue);

    cout << "Values after calling swapValues:" << endl
         << "First value =\t" << firstValue << endl
         << "Second value =\t" << secondValue << endl;

    return 0;
}
