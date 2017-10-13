// Write your own version of a program that prints the sum of a set of
// integers read from cin.

#include <iostream>

int main()
{
    int sum = 0;
    std::cout << "Enter some numbers to be added: ";
    int userInput = 0;
    while (std::cin >> userInput)
    {
       sum += userInput;
    }
    std::cout << "Total =  " << sum << std::endl;

    return 0;
}
