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

void test()
{
    // The max value of n! that an `int` can hold is 12! = 479,001,600
    cout << "============ TEST ============" << endl
         << "0!  Should = 1\t\t"
         << (fact(0) == 1 ? "[PASS]" : "[FAIL]") << endl
         << "1!  Should = 1\t\t"
         << (fact(1) == 1 ? "[PASS]" : "[FAIL]") << endl
         << "2!  Should = 2\t\t"
         << (fact(2) == 2 ? "[PASS]" : "[FAIL]") << endl
         << "3!  Should = 6\t\t"
         << (fact(3) == 6 ? "[PASS]" : "[FAIL]") << endl
         << "4!  Should = 24\t\t"
         << (fact(4) == 24 ? "[PASS]" : "[FAIL]") << endl
         << "5!  Should = 120\t"
         << (fact(5) == 120 ? "[PASS]" : "[FAIL]") << endl
         << "6!  Should = 720\t"
         << (fact(6) == 720 ? "[PASS]" : "[FAIL]") << endl
         << "7!  Should = 5040\t"
         << (fact(7) == 5040 ? "[PASS]" : "[FAIL]") << endl
         << "8!  Should = 40320\t"
         << (fact(8) == 40320 ? "[PASS]" : "[FAIL]") << endl
         << "9!  Should = 362880\t"
         << (fact(9) == 362880 ? "[PASS]" : "[FAIL]") << endl
         << "10! Should = 3628800\t"
         << (fact(10) == 3628800 ? "[PASS]" : "[FAIL]") << endl
         << "11! Should = 39916800\t"
         << (fact(11) == 39916800 ? "[PASS]" : "[FAIL]") << endl
         << "12! Should = 479001600\t"
         << (fact(12) == 479001600 ? "[PASS]" : "[FAIL]") << endl
         << "13! Should = 6227020800\t"
         << (fact(13) == 6227020800 ? "[PASS]" : "[FAIL]") << endl
         << "========== END TEST ==========" << endl;
}

int main()
{
    test();
    cout << "Factorial" << endl
         << "Enter an integer: ";
    int userInput;
    cin >> userInput;

    cout << userInput << "! = " << fact(userInput) << endl;

    return 0;
}
