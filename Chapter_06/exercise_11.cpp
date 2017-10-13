// Write and test your own version of `reset` that takes a reference.

#include <iostream>

using std::cout;
using std::endl;

void reset(int& x)
{
    x = 0;
}

int main()
{
    int testValue = 42;
    cout << "Value is: \t" << testValue << endl;
    reset(testValue);
    cout << "Value has been reset." << endl;
    cout << "New value is: \t" << testValue << endl;

    return 0;
}
