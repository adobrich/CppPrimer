// Write a program to print the size and contents of the vectors
// from exercise 3.13. Check whether your answers to the exercise
// were correct. If not, restudy § 3.3.1 (p. 97) until you understand
// why you went wrong.

#include <iostream>
#include <string>
#include <vector>

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
        for (auto element : v1)
        {
            cout << element << " ";
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
        for (auto element : v2)
        {
            cout << element << " ";
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
        for (auto element : v3)
        {
            cout << element << " ";
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
        for (auto element : v4)
        {
            cout << element << " ";
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
        for (auto element : v5)
        {
            cout << element << " ";
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
        for (auto element : v6)
        {
            cout << element << " ";
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
        for (auto element : v7)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "[empty vector]" << endl;
    }

    return 0;
}
