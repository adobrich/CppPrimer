// Rewrite the program from page 255 to use the istream constructor

#include <iostream>
#include "../include/Sales_data_v5.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    while (cin)
    {
        static Sales_data total(cin);
        if (total.isbn().empty())
        {
            cout << "No data?!" << endl;

            return -1;
        }
        Sales_data trans(cin);
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else
        {
            print(cout, total) << endl;
            total = trans;
        }
    }

    return 0;
}

