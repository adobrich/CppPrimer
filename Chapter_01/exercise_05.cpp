// We wrote the output in one large statement.  Rewrite the program to use
// a separate statement to print each operand.

#include <iostream>

int main()
{
    std::cout << "Enter two numbers: ";
    int v1 = 0;
    int v2 = 0;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    
    return 0;
}
