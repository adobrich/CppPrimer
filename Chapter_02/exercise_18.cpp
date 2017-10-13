// Write code to change the value of a pointer.
// Write code to change the value to which the pointer points.

#include <iostream>

int main()
{
    int v1 = 10;
    int v2 = 20;
    int *p1 = &v1;
    std::cout << "Initial variables:" << std::endl
              << "v1 = " << v1 << std::endl
              << "v2 = " << v2 << std::endl
              << "Initial pointer to v1:" << std::endl
              << "p1 value: " << *p1 << std::endl
              << "p1 address: " << p1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    // change value of pointer
    p1 = &v2;
    std::cout << "Change p1 to point to v2:" << std::endl;
    std::cout << "p1 value: " << *p1 << std::endl;
    std::cout << "p1 address: " << p1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    // change value to which the pointer points
    *p1 = v1;
    std::cout << "Change v2 to equal v1:" << std::endl;
    std::cout << "p1 value: " << *p1 << std::endl;
    std::cout << "p1 address: " << p1 << std::endl;

    return 0;
}
