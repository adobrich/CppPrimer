// Extend the program that assigned high pass, pass and fail grades to also
// assign low pass for grades between 60 and 75 inclusive. Write two versions:
// One version that uses only conditional operators; the other should use one
// or more `if` statements. Which version do you think is easier to understand
// and why?

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Change this
    int grade = 77;

    string finalGrade;

    finalGrade = (grade > 90) ? "High Pass" :
                 (grade > 75 ? "Pass" :
                 (grade >= 60) ? "Low Pass" : "Fail");

    cout << finalGrade << endl;

    return 0;
}
