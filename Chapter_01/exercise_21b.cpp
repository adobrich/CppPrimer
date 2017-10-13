// Write a program that reads two Sales_item objects that have the same ISBN
// and produces their sum.

// Updated to check ISBNs match as per section 1.5.2 A first look at member
// functions.

#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    std::cout << "Enter 2 sale items of the format: ISBN number_sold unit_price"
              << std::endl;
    Sales_item firstBook;
    Sales_item secondBook;
    std::cin >> firstBook >> secondBook;
    if (firstBook.isbn() == secondBook.isbn())
    {
        std::cout << firstBook + secondBook << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "Data must refer to the same ISBN." << std::endl;

        return -1;
    }
}
