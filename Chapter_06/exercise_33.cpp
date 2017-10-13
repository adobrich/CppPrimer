// Write a recursive function to print the contents of a `vector`.

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
