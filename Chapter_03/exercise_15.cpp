// Repeat the previous program but read strings this time.

#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::string;
using std::vector;


int main()
{
    cout << "Enter some words: ";
    string userInput;
    vector<string> collectedData;
    while (cin >> userInput)
    {
        collectedData.push_back(userInput);
    }

    return 0;
}
