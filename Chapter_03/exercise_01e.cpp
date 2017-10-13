// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of a rewrite of exercise 1.21

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
    Sales_data firstTransaction;
    Sales_data secondTransaction;

    // Read in two complete transactions
    if (cin >> firstTransaction.bookNo
            >> firstTransaction.units_sold
            >> firstTransaction.price &&
        cin >> secondTransaction.bookNo
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

            cout << "ISBN: " << firstTransaction.bookNo << endl
                 << "Units sold: " << totalSold << endl
                 << "Total revenue: " << totalRevenue << endl;
            if (totalSold)
            {
                cout << "Average Price (each): "
                     << totalRevenue / totalSold << endl;
            }

            return 0;
        }
        else
        {
            cerr << "Data must refer to the same ISBN." << endl;

            return -1;
        }
    }
    else
    {
        cerr << "No data or incomplete transaction" << endl
             << "Supply data of the format: ISBN units_sold price_each."
             << endl;

        return -1;
    }
}
