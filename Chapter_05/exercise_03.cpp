// Use the comma operator (§ 4.10, p. 157) to rewrite the while
// loop from § 1.4.1 (p. 11) so that it no longer requires a block.
// Explain whether this rewrite improves or diminishes the readability
// of this code.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    int val = 1;

    // Original code
    // keep executing the while as long as val is less than or equal to 10
    // while (val <= 10)
    // {
    //     sum += val;    // assigns sum + val to sum
    //     ++val;         // add 1 to val
    // }
    // cout << "Sum of 1 to 10 inclusive is "
    //      << sum << endl;

    // Rewrite using comma operator
    while (val <= 10)
        sum += val, ++val;

    cout << "Sum of 1 to 10 inclusive is "
         << sum << endl;

    return 0;
}
