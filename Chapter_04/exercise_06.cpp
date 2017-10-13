// Write an expression to determine whether an int value is even or odd

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int values[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto element: values)
    {
        if (element % 2)
        {
            cout << element << " is odd." << endl;
        }
        else
        {
            cout << element << " is even." <<endl;
        }
    }

    return 0;
}
