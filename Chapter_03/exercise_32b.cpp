// Copy the array you defined in the previous exercise into another
// array. Rewrite your program using vectors.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int vector_size = 10;
    vector<int> tenInts;

    for (auto i = 0; i != vector_size; ++i)
    {
        tenInts.push_back(i);
    }

    vector<int> tenInts_copy = tenInts;

    for (auto element : tenInts_copy)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
