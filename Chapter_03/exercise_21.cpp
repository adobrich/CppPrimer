// Redo the first exercise from § 3.3.3 (p. 105) using iterators.

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // Vectors from exercise 3.13
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1 contains " << v1.size() << " element(s): ";
    if (v1.size())
    {
        for (auto iterator = v1.cbegin(); iterator != v1.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v2 contains " << v2.size() << " element(s): ";
    if (v2.size())
    {
        for (auto iterator = v2.cbegin(); iterator != v2.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v3 contains " << v3.size() << " element(s): ";
    if (v3.size())
    {
        for (auto iterator = v3.cbegin(); iterator != v3.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v4 contains " << v4.size() << " element(s): ";
    if (v4.size())
    {
        for (auto iterator = v4.cbegin(); iterator != v4.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v5 contains " << v5.size() << " element(s): ";
    if (v5.size())
    {
        for (auto iterator = v5.cbegin(); iterator != v5.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v6 contains " << v6.size() << " element(s): ";
    if (v6.size())
    {
        for (auto iterator = v6.cbegin(); iterator != v6.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    cout << "v7 contains " << v7.size() << " element(s): ";
    if (v7.size())
    {
        for (auto iterator = v7.cbegin(); iterator != v7.cend(); ++iterator)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    return 0;
}
