// Modify our vowel-counting program so that it counts the number of
// occurrences of the following two-character sequences: ff, fl, and fi.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int ffCount = 0;
    int flCount = 0;
    int fiCount = 0;
    int spaceCount = 0;
    int tabCount = 0;
    int newLineCount = 0;
    int totalCount = 0;
    char previousLetter = '\0';
    string userInput;
    while (getline(cin, userInput))
{
    ++newLineCount;
    for (auto letter : userInput)
    {
        ++totalCount;
        switch (letter)
        {
            case 'a':
            case 'A':
                ++aCount;
                break;
            case 'e':
            case 'E':
                ++eCount;
                break;
            case 'i':
                if (previousLetter == 'f')
                {
                    ++fiCount;
                }
            case 'I':
                ++iCount;
                break;
            case 'o':
            case 'O':
                ++oCount;
                break;
            case 'u':
            case 'U':
                ++uCount;
                break;
            case ' ':
                ++spaceCount;
                break;
            case '\t':
                ++tabCount;
                break;
            case 'f':
                if (previousLetter == 'f')
                {
                    ++ffCount;
                }
                break;
            case 'l':
                if (previousLetter == 'f')
                {
                    ++flCount;
                }
                break;
        }
        previousLetter = letter;
    }
}
    cout << endl << "Processed " << totalCount << " characters." << endl;

    cout << "Number of vowel a: \t" << aCount << endl
         << "Number of vowel e: \t" << eCount << endl
         << "Number of vowel i: \t" << iCount << endl
         << "Number of vowel o: \t" << oCount << endl
         << "Number of vowel u: \t" << uCount << endl
         << "Occurrences of 'ff': \t" << ffCount << endl
         << "Occurrences of 'fl': \t" << flCount << endl
         << "Occurrences of 'fi': \t" << fiCount << endl
         << "Number of spaces: \t" << spaceCount << endl
         << "Number of tabs: \t" << tabCount << endl
         << "Number of new lines: \t" << newLineCount << endl;

    return 0;
}
