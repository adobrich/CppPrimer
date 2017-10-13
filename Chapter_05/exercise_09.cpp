// Write a program using a series of `if` statements to count the number
// of vowels in text read from `cin`.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int totalCount = 0;
    char charInput;
    while (cin >> charInput)
    {
        ++totalCount;
        if (charInput == 'a')
        {
            ++aCount;
        }
        else if (charInput == 'e')
        {
            ++eCount;
        }
        else if (charInput == 'i')
        {
            ++iCount;
        }
        else if (charInput == 'o')
        {
            ++oCount;
        }
        else if (charInput == 'u')
        {
            ++uCount;
        }
    }
    cout << endl << "Processed " << totalCount << " characters." << endl;

    cout << "Number of vowel a: \t" << aCount << endl
         << "Number of vowel e: \t" << eCount << endl
         << "Number of vowel i: \t" << iCount << endl
         << "Number of vowel o: \t" << oCount << endl
         << "Number of vowel u: \t" << uCount << endl;

    return 0;
}
