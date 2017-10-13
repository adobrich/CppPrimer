// Using an `if-else` statement, write your own version of the program
// to generate the letter grade from a numeric grade.

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> scores = { "F", "D", "C", "B", "A", "A++" };

    cout << "Enter you grade (0 - 100): ";
    int grade;
    cin >> grade;

    string letterGrade;
    if (grade < 60)
    {
        letterGrade = scores[0];
    }
    else
    {
        letterGrade = scores[(grade - 50) / 10];

        if (grade % 10 > 7)
        {
            letterGrade += '+';
        }
        else if (grade % 10 < 3)
        {
            letterGrade += '-';
        }
    }

    cout << "Score: " << letterGrade << endl;

    return 0;
}
