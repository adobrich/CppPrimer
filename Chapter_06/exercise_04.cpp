// Write and test your own version of `fact`.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int n)
{
    // if n = 0, nFactorial = 1
    // if n > 0, nFactorial = n * (n - 1) * (n - 2)...
    int nFactorial = 1;
    while (n > 1)
    {
        nFactorial *= n--;
    }
    return nFactorial;
}

int getFactorial()
{
    cout << "Factorial" << endl
         << "Enter an integer: ";
    int userInput;
    cin >> userInput;

    return fact(userInput);
}

int main()
{
    cout << "Factorial = " << getFactorial() << endl;

    return 0;
}
