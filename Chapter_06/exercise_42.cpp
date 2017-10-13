// Give the second parameter of make_plural a default argument of 's'. Test
// your program by printing singular and plural versions of the words
// `success` and `failure`.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Original function from textbook
string make_plural(size_t ctr, const string& word, const string& ending)
{
    return (ctr > 1) ? word + ending : word;
}

// New function with third parameter defaulting to 's' since changing the
// second makes no sense.
string new_make_plural(size_t ctr, const string& word, const string& ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    // Ending needs to be 'es' so we need to supply an ending
    cout << new_make_plural(1, "success", "es") << endl
         << new_make_plural(2, "success", "es") << endl;
    // Default value is 's' so we don't have to supply an ending here
    cout << new_make_plural(1, "failure") << endl
         << new_make_plural(2, "failure") << endl;

    return 0;
}
