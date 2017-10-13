// Write a program to initialize a vector from an array of ints.

#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;



int main()
{
    const int intArray[] = {1, 2, 3, 4, 5};

    vector<int> intVector (begin(intArray), end(intArray));

    for (auto element : intVector)
    {
        cout << element << endl;
    }

    return 0;
}
