// Read a sequence of words from cin and store the values in a vector.
// After you've read all the words, process the vector and change each
// word to uppercase. Print the transformed elements, eight words to a line.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::cerr;


int main()
{
    cout << "Enter some words: ";
    string userInput;
    if (cin >> userInput)
    {
        vector<string> collectedData{userInput};
        while (cin >> userInput)
        {
            collectedData.push_back(userInput);
        }
        for (auto& word : collectedData)
        {
            for (auto& letter : word)
            {
                letter = toupper(letter);
            }
        }
        for (vector<string>::size_type i = 0;
             i < collectedData.size(); ++i)
        {
            if (i > 0 && i % 8 == 0)
            {
                cout << endl;
            }

            cout << collectedData[i] << " ";
        }
        cout << endl;

        return 0;
    }
    else
    {
        cerr << endl << "No input!" << endl;

        return -1;
    }
}
