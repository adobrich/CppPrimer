#ifndef SALES_DATA_V2_HPP
#define SALES_DATA_V2_HPP

#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string isbn() const;
    Sales_data& combine(const Sales_data& transaction);

}; // Sales_data class

std::string Sales_data::isbn() const
{
    return this->bookNo;
}

Sales_data& Sales_data::combine(const Sales_data& transaction)
{
    if (this->isbn() == transaction.isbn())
    {
        this->units_sold += transaction.units_sold;
        this->revenue += transaction.revenue;
    }
    return *this;
}

#endif // SALES_DATA_V2_HPP
