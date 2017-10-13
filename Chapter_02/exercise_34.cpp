// Write a program containing the variables and assignments
// from the previous exercise. Print the variables before and
// after the assignments to check whether your predictions in the
// previous exercise were correct. If not, study the examples until
// you can convince yourself you know what led you to the wrong conclusion.

#include <iostream>

int main()
{
    int i = 0;
    int& r = i;

    const int ci = i;
    const int& cr = ci;

    auto a = r;    // a is int = 0
    auto b = ci;   // b is int = 0
    auto c = cr;   // c is int = 0
    auto d = &i;   // d is an int* = address of i = 0
    auto e = &ci;  // e is a const int* = address of ci = 0
    auto& g = ci;  // g is a  const int& = reference to ci = 0

    std::cout << "Initial definitions:" << std::endl
              << "a = " << a << std::endl
              << "b = " << b << std::endl
              << "c = " << c << std::endl
              << "d = " << d << " (" << *d << ")" << std::endl
              << "e = " << e << " (" << *e << ")" << std::endl
              << "g = " << g << " (" << g << ")" << std::endl;

    a = 42;
    b = 42;
    c = 42;
    // d = 42;     // Illegal must be dereferenced first
    *d = 42;
    // e = 42;     // Illegal pointed to type is const int
    // g = 42;     // Illegal referenced type is const int


    std::cout << "After assignment:" << std::endl
          << "a = " << a << std::endl
          << "b = " << b << std::endl
          << "c = " << c << std::endl
          << "d = " << d << " (" << *d << ")" << std::endl
          << "e = " << e << " (" << *e << ")" << std::endl
          << "g = " << g << " (" << g << ")" << std::endl;

    return 0;
}
