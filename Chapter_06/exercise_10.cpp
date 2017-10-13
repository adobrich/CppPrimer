// Using pointers, write a function to swap the values of two ints. Test the
// function by calling it and printing the swapped values.

#include <iostream>

using std::cout;
using std::endl;

void swapValues(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int firstValue = 21;
    int secondValue = 43;

    cout << "Starting values:" << endl
         << "First value =\t" << firstValue << endl
         << "Second value =\t" << secondValue << endl;

    swapValues(&firstValue, &secondValue);

    cout << "Values after calling swapValues:" << endl
         << "First value =\t" << firstValue << endl
         << "Second value =\t" << secondValue << endl;

    return 0;
}
