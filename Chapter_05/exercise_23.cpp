// Write a program that reads two integers from the standard input and
// prints the result of dividing the first number by the second.
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    int intX;
    int intY;
    cout << "Integer division: x/y" << endl
         << "Enter values for 'x' and 'y': ";
    if (cin >> intX >> intY)
    {
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
