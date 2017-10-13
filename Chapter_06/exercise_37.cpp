// Write three additional declarations for the function in the previous
// exercise. One should use a type alias, one should use a trailing return,
// and the third should use decltype. Which form do you prefer and why?

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Array for testing
string firstTenChars[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

// using statement for type alias version
using tenStrings = string[10];

// Function declarations
tenStrings& getStrings1(tenStrings& strArray);
auto getStrings2(tenStrings& strArray) -> string(&)[10];
decltype(firstTenChars)& getStrings3(tenStrings& strArray);

// Fleshed out, but kinda useless functions - just for testing
tenStrings& getStrings1(tenStrings& strArray)
{
    return strArray;
}

// Using trailing return type
auto getStrings2(tenStrings& strArray) -> string(&)[10]
{
    return strArray;
}

// Using decltype
decltype(firstTenChars)& getStrings3(tenStrings& strArray)
{
    return strArray;
}

void printArray(tenStrings& strArray)
{
    for (auto s : strArray)
    {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    // Print results of each function
    printArray(getStrings1(firstTenChars));
    printArray(getStrings2(firstTenChars));
    printArray(getStrings3(firstTenChars));

    return 0;
}

