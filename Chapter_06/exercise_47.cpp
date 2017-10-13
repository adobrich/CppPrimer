// Revise the program you wrote in the exercises in 6.3.2 (p 228) that used
// recursion to print the contents of a vector to conditionally print
// information about its execution. For example, you might print the size of
// the vector on each call. Compile and run the program with the debugging
// turned on and again with it turned off.

#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

void print_vector(vector<int>::const_iterator beg,
                  vector<int>::const_iterator end)
{
    if (beg != end) {
#ifndef NDEBUG
        cout << "Vector size: " << (end - beg) << endl;
#endif
        cout << *beg << endl;
        print_vector(++beg, end);
    }
}

int main()
{
    vector<int> test_vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    print_vector(test_vector.cbegin(), test_vector.cend());

    return 0;
}
