// Rewrite the programs again, this time using auto.

#include <iostream>

using std::cout;
using std::endl;

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

    // Print output using subscript (using auto)
    cout << "Using 'subscript' & auto:" << endl;
    for (auto i = 0; i != rowCount; ++i)
    {
        for (auto j = 0; j != colCount; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
