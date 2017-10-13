// Read a set of integers into a vector. Print the sum of each pair of
// adjacent elements. Change your program so that it prints the sum of
// the first and last elements, followed by the sum of the second and
// second-to-last, and so on.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::vector;

int main()
{
    cout << "Enter some numbers: ";
    int userInput;
    if (cin >> userInput)
    {
        vector<int> userData{userInput};
        while (cin >> userInput)
        {
            userData.push_back(userInput);
        }

        vector<int>::size_type size = userData.size();
        if (size >= 2)
        {
            for (vector<int>::size_type i = 0; i < size - 1; ++i)
            {
                cout << userData[i] + userData[i + 1] << " ";
            }
            cout << endl;

            return 0;
        }
        else
        {
            cerr << "Need at least two numbers." << endl;

            return -1;
        }
    }
    else
    {
        cerr << endl << "No input!" << endl;

        return -1;
    }
}
