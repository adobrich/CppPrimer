// Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.52 (p.24), and § 1.6 (p.25). For now, you should
// define your Sales_data class in the same file as your main function.

// Exercise 1.22 rewritten using Sales_data class.

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
    Sales_data totalSales;

    // Read in the first transaction. All subsequent matches for this
    // transactions ISBN will be used in the total, the rest will be ignored.
    if (std::cin >> totalSales.bookNo
                 >> totalSales.units_sold
                 >> totalSales.price)
    {
        totalSales.revenue = totalSales.price * totalSales.units_sold;

        Sales_data currentTransaction;
        // If there are more transactions, read and print them
        while (std::cin >> currentTransaction.bookNo
                        >> currentTransaction.units_sold
                        >> currentTransaction.price)
        {
            // If ISBNs match continue processing
            if (totalSales.bookNo == currentTransaction.bookNo)
            {
                currentTransaction.revenue = currentTransaction.price *
                                             currentTransaction.units_sold;

                totalSales.units_sold += currentTransaction.units_sold;
                totalSales.revenue += currentTransaction.revenue;
            }
        }
        std::cout << "ISBN: " << totalSales.bookNo << std::endl
                  << "Units sold: " << totalSales.units_sold << std::endl
                  << "Total revenue: " << totalSales.revenue << std::endl;

        if (totalSales.units_sold)
        {
            std::cout << "Average Price (each): "
                      << totalSales.revenue / totalSales.units_sold
                      << std::endl;
        }

        return 0;
    }
    else
    {
        std::cerr << "No data or incomplete transaction" << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }
}
