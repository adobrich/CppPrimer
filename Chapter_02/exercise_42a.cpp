// Write your own version of the Sales_data.h header and use it to rewrite
// the exercise from § 2.6.2 (p. 76).

// Exercise 1.20 rewritten using Sales_data header.

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

int main()
{
    Sales_data transaction;

    // Read in the first transaction if there is one
    if (std::cin >> transaction.bookNo
                 >> transaction.units_sold
                 >> transaction.price)
    {
        transaction.revenue = transaction.price * transaction.units_sold;

        std::cout << "ISBN: " << transaction.bookNo << std::endl
                  << "Units sold: " << transaction.units_sold << std::endl
                  << "Price (each): " << transaction.price << std::endl
                  << "Total revenue: " << transaction.revenue << std::endl
                  << std::endl;

        // If there are more transactions, read and print them
        while (std::cin >> transaction.bookNo
                        >> transaction.units_sold
                        >> transaction.price)
        {
            transaction.revenue = transaction.price * transaction.units_sold;

            std::cout << "ISBN: " << transaction.bookNo << std::endl
                      << "Units sold: " << transaction.units_sold << std::endl
                      << "Price (each): " << transaction.price << std::endl
                      << "Total revenue: " << transaction.revenue << std::endl
                      << std::endl;
        }
    }
    else
    {
        std::cerr << "No data or incomplete transaction." << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }

    return 0;
}
