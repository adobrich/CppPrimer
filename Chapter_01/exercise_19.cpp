// Revise the program you wrote for the exercises in § 1.4.1 (p.13) that
// printed a range of numbers so that it handles input in which the first
// number is smaller than the second.

// Rewrite of exercise 1.11 to handle incorrect range input

#include <iostream>

int main()
{
    std::cout << "Enter a two number range: ";
    int lowerBound = 0;
    int upperBound = 0;
    std::cin >> lowerBound >> upperBound;
    if (lowerBound > upperBound)
    {
        auto temp = lowerBound;    // store the high number in a temp variable
        lowerBound = upperBound;   // assign the low number to the correct variable
        upperBound = temp;         // assign the high number to the correct variable
    }

    while (lowerBound <= upperBound)
    {
        std::cout << lowerBound << std::endl;
        ++lowerBound;
    }

    return 0;
}
