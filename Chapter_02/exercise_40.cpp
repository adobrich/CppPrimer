// Write your own version of the Sales_data class.

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

int main()
{
    Sales_data sale;
    std::cout << "ISBN: " << sale.bookNo << std::endl
              << "Units sold: " << sale.units_sold << std::endl
              << "Price (each): " << sale.price << std::endl
              << "Total revenue: " << sale.revenue << std::endl;
    return 0;
}
