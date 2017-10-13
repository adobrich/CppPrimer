// Add constructors to your Sales_data class and write a program to use each
// of the constructors.

#include <iostream>
#include "../include/Sales_data_v4.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Sales_data first_transaction;
    Sales_data second_transaction("0-006-47988-X");
    Sales_data third_transaction("0-006-47988-X", 5, 29.95);
    cout << "Enter sale data (isbn, units sold, price each): " << endl;
    Sales_data fourth_transaction(cin);

    print(cout, first_transaction);
    cout << endl;
    print(cout, second_transaction);
    cout << endl;
    print(cout, third_transaction);
    cout << endl;
    print(cout, fourth_transaction);
    cout << endl;

    return 0;
}

