// Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.52 (p.24), and § 1.6 (p.25). For now, you should
// define your Sales_data class in the same file as your main function.

// Exercise 1.25 rewritten using Sales_data class.

#include <iostream>
#include <string>

// My version of the Sales_data class
// Included 'price' member since the incoming data contains it.
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

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
