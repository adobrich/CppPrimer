// Write a program to compare two arrays for equality. Write a similar
// program to compare two vectors.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Two vectors for comparison
    vector<int> firstVector {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> secondVector {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if (firstVector == secondVector)
    {
        cout << "Vectors match!" << endl;

        return 0;
    }
    else
    {
        cout << "Vectors don't match!" << endl;

        return -1;
    }
}
