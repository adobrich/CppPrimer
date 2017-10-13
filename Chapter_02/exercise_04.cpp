// Write a program to check whether your predictions were correct
// If not study this section until you understand what the problem is.

#include <iostream>

int main()
{
    unsigned u = 10;
    unsigned u2 = 42;
    std::cout << "unsigned int " << u2 << " - " << "unsigned int "
              << u << " = " << u2 - u << std::endl;
    std::cout << "unsigned int " << u << " - " << "unsigned int "
              << u2 << " = " << u - u2 << std::endl;

    int i = 10;
    int i2 = 42;
    std::cout << "int " << i2 << " - " << "int " <<i
              << " = " << i2 - i << std::endl;
    std::cout << "int " << i << " - " << "int " << i2
              << " = " << i - i2 << std::endl;

    std::cout << "int " << i << " - " << "unsigned " << u
              << " = " << i - u << std::endl;
    std::cout << "unsigned " << u << " - " << "int " << i
              << " = " << u - i << std::endl;

    return 0;
}
