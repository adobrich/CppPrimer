// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of a rewrite of exercise 1.20

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
    Sales_data transaction;

    // Read in the first transaction if there is one
    if (cin >> transaction.bookNo
            >> transaction.units_sold
            >> transaction.price)
    {
        transaction.revenue = transaction.price * transaction.units_sold;

        cout << "ISBN: " << transaction.bookNo << endl
             << "Units sold: " << transaction.units_sold << endl
             << "Price (each): " << transaction.price << endl
             << "Total revenue: " << transaction.revenue << endl
             << endl;

        // If there are more transactions, read and print them
        while (cin >> transaction.bookNo
                   >> transaction.units_sold
                   >> transaction.price)
        {
            transaction.revenue = transaction.price * transaction.units_sold;

            cout << "ISBN: " << transaction.bookNo << endl
                 << "Units sold: " << transaction.units_sold << endl
                 << "Price (each): " << transaction.price << endl
                 << "Total revenue: " << transaction.revenue << endl
                 << endl;
        }
    }
    else
    {
        cerr << "No data or incomplete transaction" << endl
             << "Supply data of the format: ISBN units_sold price_each."
             << endl;

        return -1;
    }

    return 0;
}
