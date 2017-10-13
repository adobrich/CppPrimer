// Use your Sales_data class to rewrite the exercises in § 1.5.1
// (p. 22), § 1.52 (p.24), and § 1.6 (p.25). For now, you should
// define your Sales_data class in the same file as your main function.

// Exercise 1.23 rewritten using Sales_data class.

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
    Sales_data currentTransaction;

    if (std::cin >> currentTransaction.bookNo
                 >> currentTransaction.units_sold
                 >> currentTransaction.price)
    {
        currentTransaction.revenue = currentTransaction.price *
                                     currentTransaction.units_sold;
        int transactionsForIsbn = 1;
        Sales_data nextTransaction;

        // Read in the rest of the transactions
        while (std::cin >> nextTransaction.bookNo
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
                std::cout << transactionsForIsbn
                          << " Transaction(s) for ISBN '"
                          << currentTransaction.bookNo << "'" << std::endl;
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
        std::cerr << "No data or incomplete transaction" << std::endl
                  << "Supply data of the format: ISBN units_sold price_each."
                  << std::endl;

        return -1;
    }

    return 0;
}
