// Write a function that takes an `int` and a pointer to and `int` and returns
// the larger of the `int` value or the value to which the pointer points.
// What type should you use for the pointer?

#include <iostream>

using std::cout;
using std::endl;

int largestValue(int ival, const int* pval)
{
    return ival > *pval ? ival : *pval;
}

int main()
{
    int x = 39;
    int y = 44;

    cout << "Compare " << x << " and " << y << endl;
    cout << largestValue(x, &y) << " is larger." << endl;

    return 0;
}
