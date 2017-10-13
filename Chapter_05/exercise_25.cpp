// Revise your program from the previous exercise to use a `try` block to
// `catch` the exception. The `catch` clause should print a message to the
// user and ask them to supply a new number and repeat the code inside the
// `try`

#include <iostream>
#include <stdexcept>

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
    while (cin >> intX >> intY)
    {
        try
        {
            if (intY == 0)
            {
                throw std::logic_error("Divide-by-zero exception.");
            }
                cout << intX << "/" << intY << " = "
                     << intX / intY << endl;
                return 0;
        }
        catch (std::logic_error err)
        {
            cout << err.what()
                 << " Try again? [y/n]: ";
            char response;
            cin >> response;
            if (!cin || response == 'n')
            {
                break;
            }
            cout << "Enter new values for 'x' and 'y': " << endl;
        }
    }
    cerr << endl << "Must supply two valid integers!" << endl;

    return -1;
}
