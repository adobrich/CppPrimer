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
            for (auto iter = userData.cbegin();
                 iter < userData.cend() - 1; ++iter)
            {
                cout << *iter + *(iter + 1) << " ";
            }
            cout << endl;

            return 0;
        }
    }
    cerr << endl << "Need at least two numbers." << endl;

    return -1;
}
