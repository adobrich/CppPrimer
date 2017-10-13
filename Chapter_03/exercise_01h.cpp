// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of a rewrite of exercise 1.25

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main()
{
    Sales_data totalTransactions;

    // Read in the first transaction
    if (cin >> totalTransactions.bookNo
            >> totalTransactions.units_sold
            >> totalTransactions.price)
    {
        totalTransactions.revenue = totalTransactions.price *
                                    totalTransactions.units_sold;

        Sales_data currentTransaction;

        // Read in the rest of the transactions
        while (cin >> currentTransaction.bookNo
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
                cout << totalTransactions.bookNo << " "
                     << totalTransactions.units_sold << " "
                     << totalTransactions.revenue << " ";
                if (totalTransactions.units_sold)
                {
                    cout << totalTransactions.revenue /
                            totalTransactions.units_sold << endl;
                }
                totalTransactions.bookNo = currentTransaction.bookNo;
                totalTransactions.units_sold = currentTransaction.units_sold;
                totalTransactions.price = currentTransaction.price;
                totalTransactions.revenue = currentTransaction.revenue;
            }
        }
        cout << totalTransactions.bookNo << " "
             << totalTransactions.units_sold << " "
             << totalTransactions.revenue << " ";
        if (totalTransactions.units_sold)
        {
            cout << totalTransactions.revenue /
                    totalTransactions.units_sold << endl;
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
