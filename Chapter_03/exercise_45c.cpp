// Rewrite the programs again, this time using auto.

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    // Dimensions of array
    constexpr size_t rowCount = 3;
    constexpr size_t colCount = 4;

    int ia[rowCount][colCount];

    // Fill ia (using auto)
    size_t count = 0;

    for (auto& row : ia)
    {
        for (auto& col : row)
        {
            col = count;
            ++count;
        }
    }
    // Initialisation code above is the same for all versions of this
    // exercise (pointer version includes the iterator header and using
    // declarations for begin and end).

    // Print output using pointers (using auto)
    cout << "Using 'pointers' & auto:" << endl;
    for (auto* p = begin(ia); p != end(ia); ++p)
    {
        for (auto* q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}
