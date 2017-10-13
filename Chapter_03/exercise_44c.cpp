// Rewrite the programs from the previous exercises using a type alias
// for the type of the loop control variables.

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

    // Type alias
    using int_array = int[colCount];

    int ia[rowCount][colCount];

    // Fill ia (using type alias)
    auto count = 0;

    for (int_array& row : ia)
    {
        for (int& col : row)
        {
            col = count;
            ++count;
        }
    }
    // Initialisation code above is the same for all versions of this
    // exercise (pointer version includes the iterator header and using
    // declarations for begin and end).

    // Print output using pointers (using type alias)
    cout << "Using 'pointers' & type alias:" << endl;

    // Type alias
    using row_pointer = int[colCount];
    using col_pointer = int;

    // for (int(*p)[rowCount + 1] = begin(ia); p != end(ia); ++p)
    for (row_pointer* p = begin(ia); p != end(ia); ++p)
    {
        for (col_pointer* q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}
