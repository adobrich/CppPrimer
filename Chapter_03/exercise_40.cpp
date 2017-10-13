// Write a program to define two character arrays initialized from
// string literals. Now define a third character array to hold the
// concatenation of the two arrays. Use strcpy and strcat to copy
// the two arrays into the third.

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char firstString[] = "Don't do";    // 8 characters
    const char secondString[] = "this!";      // 5 characters

    // firstString + secondString + space + null character
    constexpr size_t array_size = 8 + 5 + 1 + 1;
    char combinedString[array_size];

    strcpy(combinedString, firstString);
    strcat(combinedString, " ");
    strcat(combinedString, secondString);

    cout << combinedString << endl;

    return 0;
}
