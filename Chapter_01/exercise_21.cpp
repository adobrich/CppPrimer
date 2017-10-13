// Write a program that reads two Sales_item objects that have the same ISBN
// and produces their sum.

#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    std::cout << "Enter 2 sale items of the format: ISBN number_sold unit_price"
              << std::endl;
    Sales_item firstBook;
    Sales_item secondBook;
    std::cin >> firstBook >> secondBook;
    std::cout << firstBook + secondBook << std::endl;

    return 0;
}
