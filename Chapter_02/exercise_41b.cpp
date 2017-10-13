// Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.52 (p.24), and § 1.6 (p.25). For now, you should
// define your Sales_data class in the same file as your main function.

// Exercise 1.21 rewritten using Sales_data class.

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
