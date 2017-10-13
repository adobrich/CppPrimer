// Write a program to create a vector with ten int elements. Using an
// iterator, assign each element a value that is twice its current value.
// Test your program by printing the vector.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    cout << "Enter ten integers: ";
    vector<int> userInput(10);
    for (auto iter = userInput.begin(); iter != userInput.end(); ++iter)
    {
        cin >> *iter;
    }

    for (auto iter = userInput.begin(); iter != userInput.end(); ++iter)
    {
        *iter *= 2;
    }

    cout << "Result: ";
    for (auto iter = userInput.cbegin(); iter != userInput.cend() - 1; ++iter)
    {
        cout << *iter << ", ";
    }
    cout << *(userInput.cend() - 1) << endl;

    return 0;
}
