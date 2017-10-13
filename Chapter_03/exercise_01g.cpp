// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
// with appropriate using declarations.

// Rewrite of a rewrite of exercise 1.23

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
    Sales_data currentTransaction;

    if (cin >> currentTransaction.bookNo
            >> currentTransaction.units_sold
            >> currentTransaction.price)
    {
        currentTransaction.revenue = currentTransaction.price *
                                     currentTransaction.units_sold;
        int transactionsForIsbn = 1;
        Sales_data nextTransaction;

        // Read in the rest of the transactions
        while (cin >> nextTransaction.bookNo
                   >> nextTransaction.units_sold
                   >> nextTransaction.price)
        {
            nextTransaction.revenue = nextTransaction.price *
                                      nextTransaction.units_sold;

            if (currentTransaction.bookNo == nextTransaction.bookNo)
            {
                ++transactionsForIsbn;
            }
            else
            {
                cout << transactionsForIsbn
                     << " Transaction(s) for ISBN '"
                     << currentTransaction.bookNo << "'" << endl;
                transactionsForIsbn = 1;
                currentTransaction.bookNo = nextTransaction.bookNo;
                currentTransaction.units_sold = nextTransaction.units_sold;
                currentTransaction.price = nextTransaction.price;
                currentTransaction.revenue = nextTransaction.revenue;
            }
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
