// The `while` loop is particularly good at executing while some condition
// holds; for example, when we need to read values until end-of-file. The
// `for` loop is generally thought of as a step loop: An index steps through
// a range of values in a collection. Write an idiomatic use of each loop
// and then rewrite each using the other loop construct. If you could use
// only one loop, which would you choose? Why?

// `while` use case rewritten using `for` loop.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    cout << "Enter some numbers: ";
    vector<int> buffer;
    int userInput;
    for (/* not required */; cin >> userInput; buffer.push_back(userInput))
    {
        // not required
    }

    // Print buffer
    cout << "You entered: ";
    for (auto number : buffer)
    {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
