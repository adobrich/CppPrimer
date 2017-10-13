// Write a program to use a conditional operator to find the elements in a
// `vector<int>` that have odd value and double the value of each such element.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original values: ";

    for (auto element : ivec)
    {
        cout << element << " ";
    }

    cout << endl << "New values: ";

    for (auto& element : ivec)
    {
        cout << ((element % 2) ? element *= 2 : element) << " ";
    }
    cout << endl;

    return 0;
}
