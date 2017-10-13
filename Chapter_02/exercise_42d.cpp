// Write your own version of the Sales_data.h header and use it to rewrite
// the exercise from § 2.6.2 (p. 76).

// Exercise 1.23 rewritten using Sales_data header.

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

int main()
{
    Sales_data currentTransaction;

    if (std::cin >> currentTransaction.bookNo
                 >> currentTransaction.units_sold
                 >> currentTransaction.price)
    {
        currentTransaction.revenue = currentTransaction.price *
                                     currentTransaction.units_sold;
        int transactionsForIsbn = 1;
        Sales_data nextTransaction;

        // Read in the rest of the transactions
        while (std::cin >> nextTransaction.bookNo
                        >> nextTransaction.units_sold
                        >> nextTransaction.price)
        {
            nextTransaction.revenue = nextTransaction.price *
                                      nextTransaction.units_sold;

            if (currentTransaction.bookNo == nextTransaction.bookNo)
            {
                ++transactionsForIsbn;
            }
            else
            {
                std::cout << transactionsForIsbn
                          << " Transaction(s) for ISBN '"
                          << currentTransaction.bookNo << "'" << std::endl;
                transactionsForIsbn = 1;
                currentTransaction.bookNo = nextTransaction.bookNo;
                currentTransaction.units_sold = nextTransaction.units_sold;
                currentTransaction.price = nextTransaction.price;
                currentTransaction.revenue = nextTransaction.revenue;
            }
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
