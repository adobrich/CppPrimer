// Write your own version of the Sales_data.h header and use it to rewrite
// the exercise from § 2.6.2 (p. 76).

// Exercise 1.25 rewritten using Sales_data header.

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

int main()
{
    Sales_data totalTransactions;

    // Read in the first transaction
    if (std::cin >> totalTransactions.bookNo
                 >> totalTransactions.units_sold
                 >> totalTransactions.price)
    {
        totalTransactions.revenue = totalTransactions.price *
                                    totalTransactions.units_sold;

        Sales_data currentTransaction;

        // Read in the rest of the transactions
        while (std::cin >> currentTransaction.bookNo
                        >> currentTransaction.units_sold
                        >> currentTransaction.price)
        {
            currentTransaction.revenue = currentTransaction.price *
                                         currentTransaction.units_sold;

            if (totalTransactions.bookNo == currentTransaction.bookNo)
            {
                totalTransactions.units_sold += currentTransaction.units_sold;
                totalTransactions.price += currentTransaction.price;
                totalTransactions.revenue += currentTransaction.revenue;
            }
            else
            {
                std::cout << totalTransactions.bookNo << " "
                          << totalTransactions.units_sold << " "
                          << totalTransactions.revenue << " ";
                if (totalTransactions.units_sold)
                {
                    std::cout << totalTransactions.revenue /
                                 totalTransactions.units_sold << std::endl;
                }
                totalTransactions.bookNo = currentTransaction.bookNo;
                totalTransactions.units_sold = currentTransaction.units_sold;
                totalTransactions.price = currentTransaction.price;
                totalTransactions.revenue = currentTransaction.revenue;
            }
        }
        std::cout << totalTransactions.bookNo << " "
                  << totalTransactions.units_sold << " "
                  << totalTransactions.revenue << " ";
        if (totalTransactions.units_sold)
        {
            std::cout << totalTransactions.revenue /
                         totalTransactions.units_sold << std::endl;
        }
    }
    else
    {
        std::cerr << "No data or incomplete transaction" << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }

    return 0;
}
