// Write a program that reads several transactions for the same ISBN.
// Write the sum of all the transactions that were read.

#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item currentTransaction;
    Sales_item total;
    std::cin >> total;
    while (std::cin >> currentTransaction)
    {
        total += currentTransaction;
    }
    std::cout << total << std::endl;

    return 0;
}
