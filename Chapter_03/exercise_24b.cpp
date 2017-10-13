// Redo the last exercise from § 3.3.3 (p. 105) using iterators.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

int main()
{
    cout << "Enter some numbers: ";
    int userInput;
    if (cin >> userInput)
    {
        vector<int> userData {userInput};
        while (cin >> userInput)
        {
            userData.push_back(userInput);
        }

        if (userData.size() > 1)
        {
            auto beg = userData.cbegin();
            auto end = userData.cend() - 1;
            while (beg < end)
            {
                cout << *beg + *end << " ";
                ++beg;
                --end;
            }
            cout << endl;

            if (beg == end)
            {
                cout << "Middle value '" << *beg
                     << "' has nothing to do." << endl;
            }

            return 0;
        }
    }
    cerr << endl << "Need at least two numbers." << endl;

    return -1;
}
