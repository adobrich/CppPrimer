// Copy the array you defined in the previous exercise into another
// array. Rewrite your program using vectors.

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

    // Copy tenInts to tenInts_copy
    int tenInts_copy[array_size];

    for (size_t i = 0; i != array_size; ++i)
    {
        tenInts_copy[i] = tenInts[i];
    }

    for (auto element : tenInts_copy)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
