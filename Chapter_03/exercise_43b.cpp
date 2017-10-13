// Write three different versions of a program to print the elements
// of ia. One version should use a range for to manage the iteration,
// the other two should use an ordinary for loop in one case using
// subscripts and in the other using pointers. In all three programs
// write all the types directly. That is, do not use the type alias,
// auto, or decltype to simplify code.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // Dimensions of array
    constexpr size_t rowCount = 3;
    constexpr size_t colCount = 4;

    int ia[rowCount][colCount];

    // Fill ia (no auto)
    size_t count = 0;

    for (int(& row)[4] : ia)
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

    // Print output using subscript (no auto)
    cout << "Using 'subscript':" << endl;
    for (size_t i = 0; i != rowCount; ++i)
    {
        for (int j = 0; j != colCount; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
