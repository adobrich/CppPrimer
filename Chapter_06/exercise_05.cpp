// Write a function to return the absolute value of it's argument.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int getAbsolute(int x)
{
    return x < 0 ? -x : x;
}

int main()
{
    cout << "Enter value to convert to absolute vale: ";
    int userInput;
    if (cin >> userInput)
    {
        cout << "Absolute value = " << getAbsolute(userInput) << endl;
    }
    else
    {
        cerr << endl << "No valid input supplied!" << endl;

        return -1;
    }

    return 0;
}
