// Rewrite the exercises from 1.4.1 (p. 13) using for loops.
// Exercise 1.11 rewritten using a for loop.

#include <iostream>

int main()
{
    std::cout << "Enter a two number range (from low to high): ";
    int lowerBound = 0;
    int upperBound = 0;
    std::cin >> lowerBound >> upperBound;
    if (lowerBound < upperBound)
    {
        for (int i = lowerBound; i <= upperBound; ++i)
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
