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

    // Print output using range for loop (using type alias)
    cout << "Using 'range for' & type alias:" << endl;
    for (const int_array& row : ia)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}
