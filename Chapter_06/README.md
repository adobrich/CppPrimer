# Chapter Six Answers

<a name="Section_6.1">Section 6.1</a>
---
### Exercise 6.1

A parameter is a variable required by function and it is created like so:
```cpp
void someFunction(int parameter1, int parameter2)
{
    // do something fancy
}
```

An argument is the value that is supplied when calling a function, the corresponding parameter in the function header is initialised to this value.
A sample function call might look like this:
```cpp
someFunction(42, 10);
```

In this example `parameter1` is initialised to `42`, `parameter2` is initialised to `10`.

### Exercise 6.2

> (a)

This function is of type `int` but returns a string, it also declares `s` within the body of the function when it should probably be passed as an argument like below:

```cpp
string f(string s)
{
    // ...
    return s;
}
```

> (b)

This function has no type. Since there is no return statement we can assume that it is a void function.

```cpp
void f2(int i)
{
    // ...
}
```

> (c)

Parameter names must be distinct, also there is a missing curly brace `{`.

```cpp
int calc(int v1, int v2)
{
    // ...
}
```

> (d)

Missing curly braces `{}` to indicate function body & scope.

```cpp
double square(double x)
{
    return x * x;
}
```

### [Exercise 6.3](exercise_03.cpp)

Sample output:
```
$ ./Chapter_06/exercise_03 
============ TEST ============
0!  Should = 1          [PASS]
1!  Should = 1          [PASS]
2!  Should = 2          [PASS]
3!  Should = 6          [PASS]
4!  Should = 24         [PASS]
5!  Should = 120        [PASS]
6!  Should = 720        [PASS]
7!  Should = 5040       [PASS]
8!  Should = 40320      [PASS]
9!  Should = 362880     [PASS]
10! Should = 3628800    [PASS]
11! Should = 39916800   [PASS]
12! Should = 479001600  [PASS]
13! Should = 6227020800	[FAIL]
========== END TEST ==========
Factorial
Enter an integer: 5
5! = 120
```
13! fails due to integer overflow. 13! is greater than the maximum value an int can hold.

### [Exercise 6.4](exercise_04.cpp)

### [Exercise 6.5](exercise_05.cpp)

### Exercise 6.6

A parameter is part of the function header, it's value is supplied via the functions corresponding arguments. It is created when the function is called and is disposed of once the function completes.

Example of parameter usage:
```cpp
// Prints `message`
void echoMessage(string message) // message is a parameter
{
    cout << message << endl;
}

int main()
{
    echoMessage("Hello");
    
    return 0;
}
```

Output:
```
Hello
```

A local variable is created within a block or loop header and is disposed once the block/loop exits.

Example of local variable usage:
```cpp
// Prints `message` `n` times
void echoMessage(string message, int n) // message & n are parameters
{
    // i is a local variable, it doesn't exist outside
    // the for loop
    for (auto i = 0; i != n; ++i)
    {
        cout << message << endl;
    }
}

int main()
{
    echoMessage("Hello", 3);
    
    return 0;
}
```

Output:
```
Hello
Hello
Hello
```

A `static` variable is similar to a local variable but it's lifespan lasts until the program finishes, rather than just the code block or function.

Example of `static` variable usage:
```cpp
// Prints `message` `n` times and prefixes each
// line with how many times the function has been called
void echoMessage(string message, int n) // message & n are parameters
{
    // local static variable to count how many calls have been
    // made to this function
    static int executionCount = 0;
    ++executionCount;

    cout << "Call " << executionCount << " to 'echoMessage':\t";

    // i is a local variable, it doesn't exist outside
    // the for loop
    for (auto i = 0; i != n; ++i)
    {
        cout << message << " ";
    }
    cout << endl;
}

int main()
{
    echoMessage("Hello,", 3);
    echoMessage("Is there anybody in there?", 1);
    echoMessage("Just nod if you can hear me", 1);
    echoMessage("is there anyone home?", 1);
    echoMessage("Come on,", 2);
    echoMessage("Now, I hear you're feeling down", 1);
    echoMessage("well I can ease your pain", 1);
    echoMessage("Get you on your feet again", 1);
    echoMessage(".", 3);
    
    return 0;
}
```

Output:
```
Call 1 to 'echoMessage':    Hello, Hello, Hello, 
Call 2 to 'echoMessage':    Is there anybody in there? 
Call 3 to 'echoMessage':    Just nod if you can hear me 
Call 4 to 'echoMessage':    is there anyone home? 
Call 5 to 'echoMessage':    Come on, Come on, 
Call 6 to 'echoMessage':    Now, I hear you're feeling down 
Call 7 to 'echoMessage':    well I can ease your pain 
Call 8 to 'echoMessage':    Get you on your feet again 
Call 9 to 'echoMessage':    . . . 
```

### [Exercise 6.7](exercise_07.cpp)

<a name="Section_6.1.2">Section 6.1.2</a>
---
### [Exercise 6.8](../include/Chapter6.hpp)

<a name="Section_6.1.3">Section 6.1.3</a>
---
### Exercise 6.9

[fact.cpp](fact.cpp)
[factMain.cpp](factMain.cpp)

To compile manually:
```
$ clang++ -std=c++14 fact.cpp factMain.cpp -o factorial
```

This creates the executable file `factorial`.

<a name="Section_6.2.1">Section 6.2.1</a>
---
### [Exercise 6.10](exercise_10.cpp)

<a name="Section_6.2.2">Section 6.2.2</a>
---
### [Exercise 6.11](exercise_11.cpp)

### [Exercise 6.12](exercise_12.cpp)

Using references is the easier method, the objects can be passed directly to the function.

### Exercise 6.13

```cpp
void f(T);    // pass-by-value
```
This function prototype declares a function `f` which has one parameter of type `T`. The parameter of type`T` is a *copy* of whatever argument is used when the function is called. Since the parameter is a copy, no change the function makes to the parameter will affect the original argument.

```cpp
void f(T&);    // pass-by-reference
```
This version of the function prototype is similar to the previous but instead of making a *copy* of the argument supplied, it treats it as a synonym for the original argument. This means no copy takes place and any change made to the argument within the function *will* affect the original argument. This method is more efficient.

### Exercise 6.14

Use *pass-by-reference* when:
- The function is to alter the supplied argument
- The size or complexity of supplied arguments are great so that copying the object(s) would be inefficient
- arguments will always be l-values (values that *can* be used on the left hand side of an assignment)

```cpp
#include <iostream>

using std::cout;
using std::endl;

// use a reference to update a configuration option.
void toggleOption(bool& option)
{
    option = !option;
}

int main()
{
    bool autoSave = false;

    // Test toggleOption()
    for (auto i = 0; i != 5; ++i)
    {
        toggleOption(autoSave);
        cout << "Autosave is " << (autoSave ? "on." : "off.") << endl;
    }

    return 0;
}
```

Use *pass-by-value: when:*
- The function does not alter the supplied argument (and overhead is not an issue; otherwise a `const` reference might be better)
- Arguments will be r-values (values that *cannot* be used on the left hand side of an assignment)

```cpp
#include <iostream>

using std::cout;
using std::endl;

// speed in km/h, distance in km
// returns time in minutes
double minutesToDestination(double speed, double distance)
{
    return distance > 0 ? (distance / speed) * 60 : 0;
}

int main()
{
    double speed = 100;
    double distance = 25;

    cout << "You will arrive at your destination in "
         << minutesToDestination(speed, distance)
         << " minute(s)." << endl;

    return 0;
}
```

### Exercise 6.15

`const string &s` is *passed-by-reference* for efficiency as strings can be quite large. Since we do not want to make any modifications to the string it as also passed as a `const`.

`char c` is *passed-by-value* so it can be either an l-value or an r-value and we have no need to alter it's value.

`string::size_type &occurs` is *passed-by-reference* since we need to reset it's value (outside the function), then increment it as each occurrence of `char c` is found.

If `s` was made a plain reference, the program would still work as expected however it could be dangerous if later changes to the function ended up making modifications to `s`

If `occurs` was a reference to `const` we wouldn't be able to update it's value.

<a name="Section_6.2.3">Section 6.2.3</a>
---

### Exercise 6.16

```cpp
bool is_empty(const string& s)
{
    return s.empty();
}
```

By adding `const` we can now pass a `const` object, literal or an object that requires conversion to a plain reference parameter.

### Exercise 6.17

[Exercise 6.17a](exercise_17a.cpp) - Function to check if a string contains capital letters.

[Exercise 6.17b](exercise_17b.cpp) - Function change a string to all lower case letters.

The parameters used in each function are different. Since checking a string for capital letters doesn't change the string we can use `const`. This also allows us to pass `const` objects and literals as per the exercise above.

The second function changes the string so cannot be `const`.

### Exercise 6.18

> (a)

```cpp
// Compare matrix x and y, return true if they match, false otherwise.
bool compare(matrix& x, matrix& y);
```

> (b)

```cpp
// Changes the value at itr with the value x and returns the updated iterator
vector<int>::iterator change_val(int x, vector<int>::iterator itr);
```

### Exercise 6.19

> (a)

Illegal, too many arguments supplied.

> (b)

Legal, `const` literals (temporary variables) can be used.

> (c)

Legal, 66 is converted to double 66.0.

> (d)

Legal, `double` 3.8 will be converted to `int` 3.

### Exercise 6.20

Reference parameters should generally be references to `const` unless they are being used to alter the supplied argument.
When creating a plain reference which should be a reference to `const` you are limiting the types that can be used as arguments as detailed in exercise 6.16 and increasing the chance of erroneously modifying the supplied argument.

<a name="Section_6.2.4">Section 6.2.4</a>
---

### [Exercise 6.21](exercise_21.cpp)

Since we're only accessing the pointer to read it's value we should use `const int*` as the type. The plain `int` parameter can remain a plain `int` since it is a local variable within the scope of the function only.

### [Exercise 6.22](exercise_22.cpp)

### [Exercise 6.23](exercise_23.cpp)

### Exercise 6.24

In this example the parameter `ia` is actually of type `const int*`. Since an array, when used as a parameter, is converted to a pointer to the first element in that array.
The body of this function is therefore in error since we cannot guarantee there will be 10 elements. It could even be a plain `int`.
To fix this we need to enforce and array of 10 elements; we do this by changing the parameter to be a reference to an array of 10 ints like so:

```cpp
void print(const int (&ia)[10])
{
    for (size_t i = 0; i !=10; ++i)
        cout << ia[i] << endl;
}
```
Note that this version of the function is very restrictive; it can only be used with arrays of size 10.

<a name="Section_6.2.5">Section 6.2.5</a>
---

### [Exercise 6.25](exercise_25.cpp)

### [Exercise 6.26](exercise_26.cpp)

<a name="Section_6.2.6">Section 6.2.6</a>
---

### [Exercise 6.27](exercise_27.cpp)

### Exercise 6.28

Just like a `vector` the type of `elem` will be of the same type used in the definition of the `initializer_list` therefore `elem` is equal to `const string&`

### Exercise 6.29

`initializer_list` elements are always `const` and cannot be changed the only reason you would use a reference as a control variable would be to avoid copying thereby avoiding overhead.

<a name="Section_6.3.2">Section 6.3.2</a>
---

### Exercise 6.30

```
$ g++ -std=c++11 exercise_30.cpp
  exercise_30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
  exercise_30.cpp:16:13: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
               return;
               ^
```
No error message when compiling with just error 2 using `g++`.

This warning appears when using `clang++`
```
exercise_30.cpp:18:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.
```

### Exercise 6.31

A reference can only be returned when the function return type is a reference.
A reference should only be returned when it refers to a **pre-existing** object.
For a `const` reference it is the same as above except it should be used when the referred to object doesn't need to be modified.

**Never** `return` a reference to a (temporary) variable within a function as it will be removed from memory once the function ends.

### Exercise 6.32

Legal, fills array `ia` with the values 0 to 9 inclusive.
Everything is pretty self explanatory, the only part of note is the function call being assigned a value.
Since the `return` value of the function is a reference to `ia`, this is legal.

### [Exercise 6.33](exercise_33.cpp)

### [Exercise 6.34](exercise_34.cpp)

A good way to find the differences, especially when it comes to recursive functions, is to add some `cout` statements to output info at each stage though the recursion.

```cpp
int factorial(int val)
{
    static int run_count = 0;
    ++run_count;
    // Change this to != 0 and try again
    if (val > 1) {
        cout << val << " x ";
        return factorial(val - 1) * val;
    }
    // Here val is always 1 because of the explicit return value below
    cout << 1 << endl;
    cout << "Function has been run " << run_count << " times.\n";
    return 1;
}

int main()
{
    cout << factorial(5) << endl;

    return 0;
}
```

Sample output:
```
5 x 4 x 3 x 2 x 1
Function has been run 5 times.
120
```

Compare this with the output from the altered condition `(val != 0)`:
```
5 x 4 x 3 x 2 x 1 x 1
Function has been run 6 times.
120
```

We can see that the function was called an extra time. Fortunately since the returned value is 1 it doesn't change the end result.  There is however a major issue if a negative number is supplied to the function. In the altered version, supplying a negative will cause an infinite loop since `val` will never equal zero.

### Exercise 6.35

`val--` returns a *copy* of the contents of `val` (in this case the number 5) before decrementing, this value is then passed back into the recursion loop. This essentially resets `val` to 5 each recurse creating an infinite loop.

<a name="Section_6.3.3">Section 6.3.3</a>
---

### Exercise 6.36

```cpp
std::string (&getStrings())[10];
```

### [Exercise 6.37](exercise_37.cpp)

Trying out all three options, I prefer the type alias.  The style is the same as a normal function declaration and it is quite easy to follow. Trailing return is also quite easy to read, however, for consistency you'd have to make all functions use this style or the code would look quite disjointed. `decltype` also produces a very readable solution but it relies on having an array handy to match the properties, which you may not have.

### Exercise 6.38

```cpp
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd)& arrRef(int i)
{
    return (i % 2) ? odd : even; // returns a reference to the array
}

int main()
{
    // Test with even numbers
    std::cout << arrRef(2) << std::endl;
    std::cout << arrRef(2)[2] << std::endl;
    // Test with odd numbers
    std::cout << arrRef(3) << std::endl;
    std::cout << arrRef(3)[2] << std::endl;
	
    return 0;
}
```

Sample output:
```
0x92cc8bd070
4
0x92cc8bd050
5
```

<a name="Section_6.4">Section 6.4</a>
---

### Exercise 6.39

> (a)

Top level `const` is ignored.  Declarations are identical therefore the second declaration is in error.

> (b)

Simply changing the return type of an overloaded function does not differentiate it from the original declaration. The second declaration is in error.

> (c)

These definitions are legal, the parameter lists are different - one resets and `int` value, the other a `double`.

<a name="Section_6.5.1">Section 6.5.1</a>
---

### Exercise 6.40

> (a)

Legal, `a` is a mandatory argument, `b` and `c` can be left blank and the default values will be used.

> (b)

Illegal. Parameters with default values must be last in the parameter list.

### Exercise 6.41

> (a)

Illegal, no argument has been supplied for `ht`.

> (b)

Legal. `ht` = 24, `wd` = 10, `bckgrnd` = ' '.

> (c)

Legal but probably not what the programmer intended.
Since the parameter list is positional the `*` character instead of being used for `bckgrnd` is converted to an `int`, 42, and used to provide a value for `wd`.  `bckgrnd` is set using the default value `' '`.

### [Exercise 6.42](exercise_42.cpp)

<a name="Section_6.5.2">Section 6.5.2</a>
---

### Exercise 6.43

> (a)

`inline` function declarations and definitions should be placed in a header file and included in source files when required.  This is good practice since the definition of an `inline` function must match *exactly* each time it is defined.

> (b)

Function declarations like this should generally exist inside header files (depending on the programming idiom you use), the definitions should be in the source files.

### Exercise 6.44

Header file:
```cpp
#ifndef EXERCISE_6_44_HPP
#define EXERCISE_6_44_HPP

inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

#endif // EXERCISE_6_44_HPP
```

Source file:
```cpp
#include "../include/exercise_6_44.hpp"

int main()
{
    str1 = "Hello";
    str2 = "Bye";
    std::cout << (isShorter(str1, str2) ? "True" : "False") << std::endl;
	
    return 0;
}
```

Sample output:
```
False
```

### Exercise 6.45

All earlier exercises *can* be `inline` functions by placing the definitions in a header file with the `inline` specifier.  There are some considerations however - functions that will not be used in multiple source files, are non-trivial, recursive or require user input should probably not be made `inline`.
(Currently can't be bothered creating this header file.)

### Exercise 6.46

No.  The `size()` method is not a `constexpr` so `isShorter` cannot be a `constexpr`.

<a name="Section_6.5.3">Section 6.5.3</a>
---

### [Exercise 6.47](exercise_47.cpp)

Debugging is enabled by default use the `-DNDEBUG` compiler option to disable.

### Exercise 6.48

The `while` loop will accept user input until the `sought` `string` is entered or the EOF command (ctrl-d on linux) is issued.
The `assert` condition, `cin` is not a good choice since it will always equal `1` (true).  The `assert` condition should represent a value that should not be possible at this stage of execution.  A better choice would be something like:
```cp
assert(s.size() > 0 && s == sought);
```
To confirm the value stored in `s` is a logical length (just in case `sought` has been set incorrectly) and that it is in fact the value we want.

<a name="Section_6.6">Section 6.6</a>
---

### Exercise 6.49

A *candidate function* is an overloaded function (has multiple declarations using the same function name). These functions are used as candidates to resolve a function call.

A *viable function* is one or more of the above functions that have parameters that match (possibly by conversion) the arguments provided in the function call.

### Exercise 6.50

> (a)

Viable functions are:
```cpp
void f(int, int);                 // <-- Function 1
void f(double, double = 3.14);    // <-- Function 2
```
The call in this case is ambiguous since our first argument matches function two, but the second argument matches function one.

> (b)

Viable functions are:
```cpp
void f(int);                      // <-- Function 1
void f(double, double = 3.14);    // <-- Function 2
```
In this case the best match is function one as it matches exactly. Function two is a viable function via conversion (`int` -> `double`) and because of the default value.

> (c)

Viable functions are:
```cpp
void f(int, int);             // <-- Function 1
void f(int, double = 3.14)    // <-- Function 2
```
In this case the best match is function one as it matches exactly. Function two is a viable function via conversion (`int` -> `double`) for both arguments.

> (d)

Viable functions are:
```cpp
void f(int, int);             // <-- Function 1
void f(int, double = 3.14)    // <-- Function 2
```
In this case the best match is function two as it matches exactly. Function one is a viable function via conversion (`double` -> `int`) for both arguments.

### [Exercise 6.51](exercise_51.cpp)

<a name="Section_6.6.1">Section 6.6.1</a>
---

### Exercise 6.52

> (a)

`char` is *promoted* to `int`.

> (b)

`double` is *converted* to `int`.

### Exercise 6.53

> (a)

The second declaration overloads the `calc` function to allow references to `const int` as arguments.

> (b)

The second declaration overloads the `calc` function to allow pointers to `const char` as arguments.

> (c)

Top level `const` is ignored so these declarations are identical, which is illegal.

<a name="Section_6.7">Section 6.7</a>
---

### Exercise 6.54

As the book describes there are many ways to accomplish this task. Below is what I consider to be the most readable version.
```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    typedef decltype(multiply)* FP;
    vector<FP> my_vec = {10, multiply};
    int multiplier = 5;

    for (auto func : my_vec)
    {
        static int counter = 1;
        cout << func(counter, multiplier) << endl;
        ++counter;
    }

    return 0;
}
```

Sample output:
```
5
10
15
20
25
30
35
40
45
50
```

### [Exercise 6.55](exercise_55.cpp)

### Exercise 6.56

Previous exercise output:
```
20
0
100
1
```
Call made using the value `10` for both arguments for each operation. Call order is add, subtract, multiply, divide.

---
[☚ Chapter 05](../Chapter_05) Chapter 06 [Chapter 07 ☛](../Chapter_07)

[Home](https://github.com/adobrich/CppPrimer)
