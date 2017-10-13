// Write your own versions of the `fact.cc` and `factMain.cc` files.
// These files should include your `Chapter6.h` from the exercises in
// the previous section. Use these files to understand how your compiler
// supports separate compilation.

#include "../include/Chapter6.hpp"

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
