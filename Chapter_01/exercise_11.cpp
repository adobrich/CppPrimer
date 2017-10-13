// Write a program that prompts the user for two integers.  Print each
// number in the range specified by those two integers.

#include <iostream>

int main()
{
    std::cout << "Enter a two number range (from low to high): ";
    int lowerBound = 0;
    int upperBound = 0;
    std::cin >> lowerBound >> upperBound;
    if (lowerBound < upperBound)
    {
        while (lowerBound <= upperBound)
        {
            std::cout << lowerBound << std::endl;
            ++lowerBound;
        }
    }
    
    return 0;
}
