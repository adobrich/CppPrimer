// Write a program to read a sequence of ints from cin and store
// those values in a vector.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
    cout << "Enter some numbers: ";
    int userInput;
    vector<int> collectedData;
    while (cin >> userInput)
    {
        collectedData.push_back(userInput);
    }

    return 0;
}
