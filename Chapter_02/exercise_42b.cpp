// Write your own version of the Sales_data.h header and use it to rewrite
// the exercise from § 2.6.2 (p. 76).

// Exercise 1.21 rewritten using Sales_data header.

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

int main()
{
    Sales_data firstTransaction;
    Sales_data secondTransaction;

    // Read in two complete transactions
    if (std::cin >> firstTransaction.bookNo
                 >> firstTransaction.units_sold
                 >> firstTransaction.price &&
        std::cin >> secondTransaction.bookNo
                 >> secondTransaction.units_sold
                 >> secondTransaction.price)
    {
        // If ISBNs match continue processing
        if (firstTransaction.bookNo == secondTransaction.bookNo)
        {
            firstTransaction.revenue = firstTransaction.price *
                                       firstTransaction.units_sold;
            secondTransaction.revenue = secondTransaction.price *
                                        secondTransaction.units_sold;

            auto totalSold = firstTransaction.units_sold +
                             secondTransaction.units_sold;
            auto totalRevenue = firstTransaction.revenue +
                                secondTransaction.revenue;

            std::cout << "ISBN: " << firstTransaction.bookNo << std::endl
                      << "Units sold: " << totalSold << std::endl
                      << "Total revenue: " << totalRevenue << std::endl;
            if (totalSold)
            {
                std::cout << "Average Price (each): "
                          << totalRevenue / totalSold << std::endl;
            }

            return 0;
        }
        else
        {
            std::cerr << "Data must refer to the same ISBN." << std::endl;

            return -1;
        }
    }
    else
    {
        std::cerr << "No data or incomplete transaction" << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }
}
