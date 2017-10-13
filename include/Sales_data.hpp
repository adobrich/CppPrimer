#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;

}; // Sales_data class

#endif // SALES_DATA_HPP
