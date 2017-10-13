// The program in this section used the prefix increment and decrement
// operators. Explain why we used prefix and not postfix. What changes
// would have to be made to use the postfix versions? Rewrite the program
// using postfix operators.

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec (5, 0);

    vector<int>::size_type cnt = ivec.size();

    // Assign values from cnt... 1 to the elements in ivec
    // Prefix or postfix increment/decrement doesn't matter with for loops
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    {
        ivec[ix] = cnt;
    }

    for (auto element : ivec)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
