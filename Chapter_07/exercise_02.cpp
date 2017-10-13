// Add the combine and isbn members to the Sales_data class you wrote for the
// exercises in § 2.6.2 (p. 76).

#include <iostream>
#include <string>
#include "../include/Sales_data_v2.hpp"

void print_data(const Sales_data& data)
{
    std::cout << "\tISBN: " << data.bookNo << std::endl
              << "\tUnits sold: " << data.units_sold << std::endl
              << "\tTotal revenue: " << data.revenue << std::endl;
}

int main()
{
    Sales_data total;
    Sales_data sale;

    total.bookNo = "0-006-47988";
    total.units_sold = 10;
    total.revenue = 50.0;

    sale.bookNo = "0-006-47988";
    sale.units_sold = 5;
    sale.revenue = 50.0;

    std::cout << "First transaction:" << std::endl;
    print_data(total);
    std::cout << "Second transaction:" << std::endl;
    print_data(sale);
    std::cout << "Transactions combined:" << std::endl;
    print_data(total.combine(sale));

    return 0;
}
