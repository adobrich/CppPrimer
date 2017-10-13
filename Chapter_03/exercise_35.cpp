// Using pointers, write a program to set the elements in an array to zero.

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    // Array to reset to zero
    int tenInts[10];

    int* currentElement = begin(tenInts);
    int* lastElement = end(tenInts);

    while (currentElement != lastElement)
    {
        *currentElement = 0;
        ++currentElement;
    }

    for (auto element : tenInts)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
