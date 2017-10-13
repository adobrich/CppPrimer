// Write all four versions of f. Each function should print a distinguishing
// message. Check your answers for the previous exercises. If your answers
// were incorrect, study this section until you understand why your answers
// were wrong.

#include <iostream>

using std::cout;
using std::endl;

void f()
{
    cout << "f()" << endl;
}

void f(int)
{
    cout << "f(int)" << endl;
}

void f(int, int)
{
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "f(double, double = 3.14)" << endl;
}

int main()
{
	// f(2.56, 42); <-- Ambiguous call
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}

