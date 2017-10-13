// Write a function to swap two `int` pointers

#include <iostream>

using std::cout;
using std::endl;

void swapPointer(int*& ptr1, int*& ptr2)
{
    auto temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int main()
{
    int firstValue = 41;
    int secondValue = 55;

    auto firstPointer = &firstValue;
    auto secondPointer = &secondValue;

    cout << "Starting values:" << endl
         << "First value =\t" << *firstPointer << endl
         << "Second value =\t" << *secondPointer << endl;

    swapPointer(firstPointer, secondPointer);

    cout << "Values after calling swapPointer:" << endl
         << "First value =\t" << *firstPointer << endl
         << "Second value =\t" << *secondPointer << endl;

    return 0;
}
