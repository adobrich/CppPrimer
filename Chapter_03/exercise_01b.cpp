// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of exercise 1.10

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int v1 = 10;
    while ( v1 >= 0)
    {
        cout << v1 << endl;
        --v1;
    }

    return 0;
}
