// Revise the loop that printed the first paragraph in text to instead
// change the elements in text that correspond to the first paragraph
// to all uppercse. After you've updated text, print its contents.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> text;
    text.push_back("This is the first paragraph.");
    text.push_back("This is still part of the first paragraph.");
    text.push_back("");
    text.push_back("This is the second paragraph.");
    text.push_back("");
    text.push_back("This is the third paragraph.");

    // Iterate over the text vector until we reach an empty element
    // or the end of the vector
    for (auto textIter = text.begin();
         textIter != text.end() && !textIter->empty(); ++textIter)
    {
        // iterate over the string within the vector and change each
        // character to upper case
        for (auto strIter = textIter->begin();
             strIter != textIter->end(); ++strIter)
        {
            *strIter = toupper(*strIter);
        }
    }
    // Print the results
    for (auto textIter = text.cbegin();
         textIter != text.cend(); ++textIter)
    {
        cout << *textIter << endl;
    }

    return 0;
}
