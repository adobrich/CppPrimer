#ifndef SALES_DATA_V7_HPP
#define SALES_DATA_V7_HPP

#include <istream>
#include <string>

struct Sales_data
{
friend Sales_data add(const Sales_data& first_transaction,
                      const Sales_data& second_transaction);
friend std::istream& read(std::istream& input, Sales_data& transaction);
friend std::ostream& print(std::ostream& output, const Sales_data& transaction);

public:
    Sales_data()
        : bookNo("")
        , units_sold(0)
        , revenue(0.0)
    { }

    Sales_data(const std::string& book_isbn) : bookNo(book_isbn) {}

    Sales_data(const std::string& book_isbn, unsigned units, double price)
        : bookNo(book_isbn)
        , units_sold(units)
        , revenue(units * price)
    { }

    Sales_data(std::istream& input)
    {
        read(input, *this);
    }

    std::string isbn() const;
    Sales_data& combine(const Sales_data& transaction);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

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

Sales_data add(const Sales_data& first_transaction, const Sales_data& second_transaction)
{
    Sales_data sum = first_transaction;
    sum.combine(second_transaction);
    return sum;
}

std::istream& read(std::istream& input, Sales_data& transaction)
{
    double price = 0.0;
    input >> transaction.bookNo >> transaction.units_sold >> price;
    transaction.revenue = transaction.units_sold * price;
    return input;
}

std::ostream& print(std::ostream& output, const Sales_data& transaction)
{
    output << transaction.isbn() << " "
           << transaction.units_sold << " "
           << transaction.revenue;
    return output;
}

#endif // SALES_DATA_V7_HPP
