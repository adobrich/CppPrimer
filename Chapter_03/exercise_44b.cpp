// Rewrite the programs from the previous exercises using a type alias
// for the type of the loop control variables.

#include <iostream>

using std::cout;
using std::endl;

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

    for (int_array &row : ia)
    {
        for (int &col : row)
        {
            col = count;
            ++count;
        }
    }
    // Initialisation code above is the same for all versions of this
    // exercise (pointer version includes the iterator header and using
    // declarations for begin and end).

    // Print output using subscript (using type alias)
    cout << "Using 'subscript' using type alias:" << endl;

    // Type alias
    using current_row = size_t;
    using current_col = size_t;

    for (current_row i = 0; i != rowCount; ++i)
    {
        for (current_col j = 0; j != colCount; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
