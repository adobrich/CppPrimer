// Rewrite your grading program to use the conditional operator
// (§ 4.7, p. 151) in place of the `if-else` statement.

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

    letterGrade = (grade < 60) ? scores[0] :
                   scores[(grade - 50) / 10];

    letterGrade += (grade < 60 || grade == 100) ? '\0' :
                   (grade % 10 > 7) ? '+' :
                   (grade % 10 < 3) ? '-' : '\0';

    cout << "Score: " << letterGrade << endl;

    return 0;
}
