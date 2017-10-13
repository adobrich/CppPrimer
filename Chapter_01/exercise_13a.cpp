// Rewrite the exercises from 1.4.1 (p. 13) using for loops.
// Exercise 1.09 rewritten using a for loop.

#include <iostream>

int main ()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "The sum of the numbers from 50 to 100 inclusive is: "
              << sum << std::endl;

    return 0;
}
