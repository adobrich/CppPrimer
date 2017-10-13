// Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.52 (p.24), and § 1.6 (p.25). For now, you should
// define your Sales_data class in the same file as your main function.

// Exercise 1.20 rewritten using Sales_data class.

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
        std::cerr << "No data or incomplete transaction" << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }

    return 0;
}
