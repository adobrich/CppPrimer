// The `while` loop is particularly good at executing while some condition
// holds; for example, when we need to read values until end-of-file. The
// `for` loop is generally thought of as a step loop: An index steps through
// a range of values in a collection. Write an idiomatic use of each loop
// and then rewrite each using the other loop construct. If you could use
// only one loop, which would you choose? Why?

// `for` use case.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter a number: ";
    int userInput;
    cin >> userInput;
    int sum = 0;
    for (auto i = 1; i <= userInput; ++i)
    {
        sum += i;
    }

    cout << "Sum of 1 to " << userInput << " inclusive is: "
         << sum << endl;

    return 0;
}
