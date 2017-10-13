// Write a `main` function that takes two arguments.
// Concatenate the supplied arguments and print the resulting `string`.

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    // This check for null pointer is probably redundant since
    // argv will always contain the name of the program as the
    // first element.
    if (argv) {
        // This works because there is a terminating `0` added
        // to the end of the argv array
        while (*argv) {
            cout << *argv++ << endl;
        }
    }

    return 0;
}
