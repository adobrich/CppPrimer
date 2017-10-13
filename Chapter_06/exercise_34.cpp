// What would happen if the stopping condition in `factorial` were `if (val != 0)`

#include <iostream>

using std::cout;
using std::endl;

int factorial(int val)
{
    static int run_count = 0;
    ++run_count;
    if (val > 1) {
        cout << val << " x ";
        return factorial(val - 1) * val;
    }
    // Here val is always 1 because of the explicit return value below
    cout << 1 << endl;
    cout << "Function has been run " << run_count << " times.\n";
    return 1;
}

int main()
{
    cout << factorial(5) << endl;

    return 0;
}
