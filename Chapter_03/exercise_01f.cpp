// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of a rewrite of exercise 1.22

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

// My version of the Sales_data class
// Included 'price' member since the incoming data contains it.
struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

int main()
{
    Sales_data totalSales;

    // Read in the first transaction. All subsequent matches for this
    // transactions ISBN will be used in the total, the rest will be ignored.
    if (cin >> totalSales.bookNo
            >> totalSales.units_sold
            >> totalSales.price)
    {
        totalSales.revenue = totalSales.price * totalSales.units_sold;

        Sales_data currentTransaction;
        // If there are more transactions, read and print them
        while (cin >> currentTransaction.bookNo
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
        cout << "ISBN: " << totalSales.bookNo << endl
             << "Units sold: " << totalSales.units_sold << endl
             << "Total revenue: " << totalSales.revenue << endl;

        if (totalSales.units_sold)
        {
            cout << "Average Price (each): "
                 << totalSales.revenue / totalSales.units_sold
                 << endl;
        }

        return 0;
    }
    else
    {
        cerr << "No data or incomplete transaction" << endl
             << "Supply data of the format: ISBN units_sold price_each."
             << endl;

        return -1;
    }
}
