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

    // Print output using range for loop (using auto)
    cout << "Using 'range for' & auto:" << endl;
    for (const auto& row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}
