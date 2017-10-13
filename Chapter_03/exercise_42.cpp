// Write a program to copy a vector of ints into an array of ints.

#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::begin;
using std::end;


int main() {
    const vector<int> intVector = {1, 2, 3, 4, 5};

    int intArray[5];

    const auto arraySize = end(intArray) - begin(intArray);

    if (intVector.end() - intVector.begin() == arraySize) {
        for (auto i = 0; i != arraySize; i++) {
            intArray[i] = intVector[i];
        }
    } else {
        cerr << "Array size does not match vector size!" << endl;

        return -1;
    }

    for (auto element : intArray) {
        cout << element << endl;
    }

    return 0;
}
