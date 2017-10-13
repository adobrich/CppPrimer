// Revise your program to `throw` an exception if the second number is zero.
// Test your program with a zero input to see what happens on your system
// if you don't catch an exception.

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::cerr;

int main()
{
    int intX;
    int intY;
    cout << "Integer division: x/y" << endl
         << "Enter values for 'x' and 'y': ";
    if (cin >> intX >> intY)
    {
        if (intY == 0)
        {
            throw runtime_error("Divide-by-zero exception.");
        }
            cout << intX << "/" << intY << " = "
                 << intX / intY << endl;
    }
    else
    {
        cerr << endl << "Must supply two integers!" << endl;
        return -1;
    }

    return 0;
}
