// Rewrite the grade clustering program from § 3.3.3 (p. 104) using
// iterators instead of subscripts.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            *(scores.begin() + grade / 10) += 1;
        }
    }
    for (auto iter = scores.cbegin(); iter != scores.cend() -1; ++iter)
    {
        cout << *iter << " ";
    }
    cout << *(scores.cend() - 1) << endl;

    return 0;
}
