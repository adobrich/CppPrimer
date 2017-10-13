// Write a program to compare two strings. Now write a program to compare
// the values of two C-style character strings.

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{

    const char cStringOne[] = "Hello";
    const char cStringTwo[] = "Helloo";

    auto cStringComparison = strcmp(cStringOne, cStringTwo);

    if (cStringComparison == 0)
    {
        cout << "Strings match!" << endl;
    }
    else if (cStringComparison > 0)
    {
        cout << "'" << cStringOne << "' is greater than '"
             << cStringTwo << "'" << endl;
    }
    else
    {
        cout << "'" << cStringOne << "' is less than '"
             << cStringTwo << "'" << endl;
    }
    return 0;

}
