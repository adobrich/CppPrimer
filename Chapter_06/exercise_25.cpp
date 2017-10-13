// Write a `main` function that takes two arguments.
// Concatenate the supplied arguments and print the resulting `string`.

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    if (argc == 3) {
        cout << argv[1] << " " << argv[2] << endl;

        return 0;
    } else if (argc < 3) {
        cout << "Too few command line arguments." << endl;

        return -1;
    } else {
        cout << "Too many command line arguments." << endl;

        return -1;
    }
}
