// Determine the types deduced in each of the following definitions.
// Once you've figured out the types, write a program to see whether
// you were correct.

#include <iostream>

int main()
{
    const int i = 42;       // i = const int
    auto j = i;             // j = int
    const auto& k = i;      // k = const int&
    auto* p = &i;           // p = const int*
    const auto j2 = i;      // j2 = const int
    const auto& k2 = i;     // k2 = const int&

    // The base type for variable i is an int therefore all deduced
    // types will be int so long as there are no conversions or casts.
    // Since all of these examples are auto definitions, we can safely
    // assume all deduced types in this exercise are int. We'll test this by
    // dividing each definition by 4, which should equal 10.5 in each case,
    // but will instead be narrowed to 10 since integers don't have a
    // fractional component.

    std::cout << "Test 1:"
              << "\nDivide all vairables by 4 to check they are all ints."
              << "\nIf they are the result will be 10, otherwise 10.5."
              << "\nj/4 = " << j / 4
              << "\nk/4 = " << k / 4
              << "\n*p/4 = " << *p / 4
              << "\nj2/4 = " << j2 / 4
              << "\nk2/4 = " << k2 / 4
              << "\n-------------------------------------------------------\n";

    std::cout << "\nTest 2:"
              << "\nPrint where in memory each variable is stored."
              << "\nReferences will have the same address as i since"
              << "\nthey are not objects, but rather synonyms for i."
              << "\nj and j2 will have different addresses since they"
              << "\nare new variables with the value of i copied into them."
              << "\np will have a new address since it is a new object, it's"
              << "\nvalue will be the address of i."
              << "\nMemory Address of i  =\t" << std::addressof(i)
              << "\nMemory Address of j  =\t" << std::addressof(j) << " (new int)"
              << "\nMemory Address of k  =\t" << std::addressof(k) << " (Reference)"
              << "\nMemory Address of p  =\t" << std::addressof(p) << " (new pointer)"
              << "\np's held Address     =\t" << p << " (pointed to object)"
              << "\nMemory Address of j2 =\t" << std::addressof(j2) << " (new int)"
              << "\nMemory Address of k2 =\t" << std::addressof(k2) << " (Reference)"
              << "\n-------------------------------------------------------\n";

    std::cout << "\nTest 3:"
              << "\nAttempt to increment each variable to determine which are"
              << "\nconst. All but one of these tests is illegal and therefore"
              << "\ncommented out."
              << "\n++i  = " << /* ++i */ "illegal, is const"
              << "\n++j  = " << ++j
              << "\n++k  = " << /* ++k */ "illegal, is const"
              << "\n++*p = " << /* ++*p */ "illegal, is const"
              << "\n++j2 = " << /* ++j2 */ "illegal, is const"
              << "\n++k2 = " << /* ++k2 */ "illegal, is const\n";

    return 0;
}
