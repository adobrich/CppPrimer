// Write a version of the transaction-processing program from § 1.6 (p. 24)
// using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

#include <iostream>
#include <string>
#include "../include/Sales_data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Sales_data total;
    if (cin >> total.bookNo
            >> total.units_sold
            >> total.revenue)
    {
        Sales_data transaction;
        while (cin >> transaction.bookNo
                   >> transaction.units_sold
                   >> transaction.revenue)
        {
            if (total.bookNo == transaction.bookNo)
            {
                total.units_sold += transaction.units_sold;
                total.revenue += transaction.revenue;
            }
            else
            {
                cout << "ISBN: " << total.bookNo << endl
                     << "Units sold: " << total.units_sold << endl
                     << "Total revenue: " << total.revenue << endl
                     << endl;
                total = transaction;
            }
        }
        cout << "ISBN: " << total.bookNo << endl
             << "Units sold: " << total.units_sold << endl
             << "Total revenue: " << total.revenue << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;

        return -1;
    }

    return 0;
}

