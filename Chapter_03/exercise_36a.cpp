// Write a program to compare two arrays for equality. Write a similar
// program to compare two vectors.

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    // Two arrays for comparison
    int firstArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int secondArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* ia2element = secondArray;

    if (end(firstArray) - begin(firstArray) ==
        end(secondArray) - begin(secondArray))
    {
        for (auto element : firstArray)
        {
            if (element != *ia2element)
            {
                cout << "Arrays do not match!" << endl;

                return -1;
            }
            ++ia2element;
        }
        cout << "Arrays match!" << endl;

        return 0;
    }
    else
    {
        cout << "Arrays do not match!" << endl;

        return -1;
    }

}
