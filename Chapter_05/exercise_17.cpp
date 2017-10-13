// Given two `vectors` of ints, write a program to determine whether
// one `vector` is a prefix of the other. For vectors of unequal length,
// compare the number of elements of the smaller `vector`. For example,
// given the vectors containing `0, 1, 1` and `2` and `0, 1, 1, 2, 3, 5, 8`,
// respectively your program should return true.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Change these
    vector<int> ivec { 0, 1, 1, 2 };
    vector<int> ivec2 { 0, 1, 1, 2, 3, 5, 8 };

    vector<int>* shortestVector = ivec.size() > ivec2.size() ? &ivec2 : &ivec;
    decltype(shortestVector->size()) i = 0;

    for ( /* init not required */;
         ivec[i] == ivec2[i] && i != shortestVector->size();
         ++i)
    {
        // body not required
    }

    cout << (i < shortestVector->size() ? "False" : "True") << endl;

    return 0;
}
