// Parenthesize the following expression to show how it is evaluated.
// Test your answer by compiling the expression (without parentheses)
// and printing its result.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Original: "
         << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
    cout << "Parenthesized: "
         << ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) << endl;

    return 0;
}
