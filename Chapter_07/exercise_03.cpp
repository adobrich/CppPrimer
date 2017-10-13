// Revise your transaction-processing program from § 7.1.1 (p. 256) to use
// these members

#include <iostream>
#include <string>
#include "../include/Sales_data_v2.hpp"

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
            if (total.isbn()  == transaction.isbn())
            {
                total.combine(transaction);
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

