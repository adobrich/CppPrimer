// Write a program to define an array of ten ints. Give each element
// the same value as its position in the array.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    constexpr size_t array_size = 10;
    int tenInts[array_size];

    for (size_t i = 0; i != array_size; ++i)
    {
        tenInts[i] = i;
    }

    for (auto element : tenInts)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
