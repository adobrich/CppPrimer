// Write a program that reads several transactions and counts how many
// transactions occur for each ISBN.

#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item currentTransaction;
    Sales_item total;
    if (std::cin >> currentTransaction)
    {
        int totalTransactions = 1;
        while (std::cin >> total)
        {
            if (currentTransaction.isbn() == total.isbn())
            {
                ++totalTransactions;
            }
            else
            {
                std::cout << totalTransactions << " Transaction(s) for ISBN '"
                          << currentTransaction.isbn() << "'" << std::endl;
                totalTransactions = 1;
                currentTransaction = total;
            }
        }
    }

    return 0;
}
