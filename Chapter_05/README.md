# Chapter Five Answers

<a name="Section_5.1">Section 5.1</a>
---
### Exercise 5.1

A null statement is an empty statement it is written as a single semicolon `;`.

A null statement can be used wherever a normal statement is expected. It can be useful for loops where the body of the loop is not required, or for writing valid 'placeholder code' when fleshing out an idea.

### Exercise 5.2

A block is series of statements (zero or more) enclosed in curly braces
```cpp
{
    // This is a
    // Code block
}
```

Blocks can be used to evaluate multiple lines of code where one line is expected, such as a `while` loop.
The body of the `while` loop expects a single statement for the body, by using curly braces multiple lines can be executed each iteration of the loop; just as we've seen in previous exercises.

### [Exercise 5.3](exercise_03.cpp)

Using the comma `,` operator is slightly less readable in this case. If there were more than two statements the readability would diminish rapidly. Searching for errors in the code would also become difficult since all the statements are on the same line. Having statements on their own line makes debugging much easier.

<a name="Section_5.2">Section 5.2</a>
---
### Exercise 5.4

> (a)

This code attempts to compare a declaration to an iterator, which is illegal.
To fix this code we would have to declare the iterator outside the `while` statement, like so:
```cpp
auto iter = s.begin();
while (iter != s.end())
{
    // ...
    // increment code ...
}
```

> (b)

So long as `find(word)` returns a value other than zero/false the loop will run. As soon as a zero/false is returned, the `if` statement will run and fail since `status` is an out-of-scope variable (undefined in the current scope).

To fix this we *could* define `status` outside the `while` loop and assign it to `find(word)` for the initial value, then in the body of the `while` loop update `status` to the next value:


```cpp
bool status = find(word);
while (status)
{
    // do something when true ...
    status = find(word);
}
if (!status) // <-- redundant statement
{
    // do something when false ...
}
```

Another option is to remove the `if` statement all together.
If we are outside the `while` loop, that means that `status` is false (`!status`), so checking if `status` is false in the `if` statement is redundant. We could rewrite the code as follows:
```cpp
while (bool status = find(word))
{
    // do something when true ...
}

// do something when false ...
```

The second option is probably the one to go with if `status` is not required anywhere else in the program, use the first option otherwise (but drop the `if` statement, it's not required).

<a name="Section_5.3.1">Section 5.3.1</a>
---
### [Exercise 5.5](exercise_05.cpp)

### [Exercise 5.6](exercise_06.cpp)

### Exercise 5.7

> (a)

```cpp
if (ival1 != ival2)
    ival1 = ival2;    // <-- Missing semicolon
else
    ival1 = ival2 = 0;
```

> (b)

```cpp
if (ival < minval)
{   // <-- Require block for multiple statements
    minval = ival;
    occurs = 1;
}   // <-- End block
```

> (c)

```cpp
if (int ival = get_value())
    cout << "ival = " << ival << endl;
else    // <-- Use an else to keep ival in scope
    cout << "ival = 0\n";
```

> (d)

```cpp
if (ival == 0)    // <-- Should be equality instead of assignment
    ival = get_value();
```

### Exercise 5.8

The "dangling `else`" is the issue that arises when there are more `if` statements than there are `else` branches. The problem is determining which `else` belongs to which `if`.
C++ uses proximity to determine ownership; the closest unmatched `if` (an `if` without an `else` branch) in the preceding code is the owner.

<a name="Section_5.3.2">Section 5.3.2</a>
---
### [Exercise 5.9](exercise_09.cpp)

See [lorem_ipsum.txt](../data/lorem_ipsum.txt) for sample input file.

Usage (from within the build directory):
```
./Chapter_05/exercise_09 < ../data/lorem_ipsum.txt
```
Sample output:
```
Processed 1072 characters.
Number of vowel a: 	87
Number of vowel e: 	140
Number of vowel i: 	100
Number of vowel o: 	60
Number of vowel u: 	65
```

### Exercise 5.10

Option 1: the previous example can be salvaged if we use `tolower()` when comparing. [Exercise 5.10a](exercise_10a.cpp)

Option 2: rewrite program using a switch statement (The better option, and probably more inline with the question). [Exercise 5.10b](exercise_10b.cpp)

### [Exercise 5.11](exercise_11.cpp)

### [Exercise 5.12](exercise_12.cpp)

### Exercise 5.13

> (a)

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a':
        aCnt++;
        break;    // <-- Missing break;
    case 'e':
        eCnt++;
        break;    // <-- Missing break;
    default: iouCnt++;
}
```

> (b)

If the `default:` case is evaluated it will fail because the declaration of `ix` is inside `case 1:`, which is not evaluated in this case. 

```cpp
int ix;    // <-- Declare outside of switch
unsigned index = some_value();
switch (index) {
    case 1:
        ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ix] = index;
}
```

> (c)


```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1:          // <-- One condition per case
    case 3:
    case 5:
    case 7:
    case 9:
        oddCnt++;    // <-- Fix variable name typo
        break;
    case 2:          // <-- One condition per case
    case 4:
    case 6:
    case 8:
    case 10:
        evenCnt++;    // <-- Fix variable name typo
        break;
}
```

> (d)

```cpp
// Case conditions must be compile time constants
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned buffsize;
unsigned swt = get_buffCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

<a name="Section_5.4.1">Section 5.4.1</a>
---
### [Exercise 5.14](exercise_14.cpp)

<a name="Section_5.4.2">Section 5.4.2</a>
---
### Exercise 5.15

> (a)

The `if` statement below the for loop is in error. `ix` is out of scope here. `ix` is only available in the `for` header and body. To fix we remove the `if` statement; if the `for` loop has exited that means the condition is false, therefore the `if` condition was redundant anyway.
```cpp
for (int ix = 0; ix != sz; ++ix)
{
    // ...
}
```
This loop runs `sz` times, incrementing `ix` and testing the condition each loop.

> (b)

The init statement for this loop is missing.

```cpp
int ix;
for (ix = 0; ix != sz; ++ix)
{
    // ...
}
```

Same as the above `for` loop, this loop runs `sz` times, incrementing `ix` (now global scope) and testing the condition each loop.

> (c)

This loop will run forever since `sz` is incremented each loop.

```cpp
for (int ix = 0; ix != sz; ++ix)
{
    // ...
}
```

Same as the first for loop.

### Exercise 5.16

[Exercise 5.16a](exercise_16a.cpp) `while` use case.
[Exercise 5.16b](exercise_16b.cpp) `for` use case.
[Exercise 5.16c](exercise_16c.cpp) rewrite of exercise 5.16a using a `for` loop.
[Exercise 5.16d](exercise_16d.cpp) rewrite of exercise 5.16b using a `while` loop.

If I had to choose, I would take the `for` loop. Most of the work is done in the header, the variables are local to the `for` loop (no need to define variables outside the loop), the `for` loop is a bit more flexible than the `while` loop.

### [Exercise 5.17](exercise_17.cpp)

<a name="Section_5.4.4">Section 5.4.4</a>
---
### Exercise 5.18

> (a)

This code is missing the braces `{}` for the body.

```cpp
do
{
    int v1, v2;
    cout << "Please enter two numbers to sum: ";
    if (cin >> v1 >> v2)
    {
        cout << "Sum is: " << v1 + v2 << endl;
    }
}
while (cin);
```

> (b)

The `do while` loop does not allow variable definitions inside the condition. These variables must be defined outside the loop.

```cpp
int ival;
do
{
    // ...
}
while (ival = get_response());
```

```
do {
    int ival = get_response();
} while (ival);
```

`ival` is out of scope when used inside the condition. `ival` must be declared outside of the loop.

```cpp
int ival;
do
{
    ival = get_response();
}
while (ival);
```

<a name="Section_5.5.1">Section 5.5.1</a>
---
### [Exercise 5.20](exercise_20.cpp)

<a name="Section_5.5.2">Section 5.5.2</a>
---
### [Exercise 5.21](exercise_21.cpp)

<a name="Section_5.5.3">Section 5.5.3</a>
---
### Exercise 5.22

Rewrite using a loop:
```cpp
int sz;
do
{
    sz = get_size();
}
while (sz <= 0);
```

<a name="Section_5.6.3">Section 5.6.3</a>
---
### [Exercise 5.23](exercise_23.cpp)

### [Exercise 5.24](exercise_24.cpp)

Result of uncaught divide-by-zero exception:
```
$ ./Chapter_05/exercise_23
Integer division: x/y
Enter values for 'x' and 'y': 6 0
Floating point exception (core dumped)
```

Result of caught divide-by-zero exception:
```
$ ./Chapter_05/exercise_24
Integer division: x/y
Enter values for 'x' and 'y': 6 0 
terminate called after throwing an instance of 'std::runtime_error'
  what():  Divide-by-zero exception.
Aborted (core dumped)
```

### [Exercise 5.25](exercise_25.cpp)

Sample output:
```
$ ./Chapter_05/exercise_25 
Integer division: x/y
Enter values for 'x' and 'y': 6 0
Divide-by-zero exception. Try again? [y/n]: n

Must supply two valid integers!
```

---
[☚ Chapter 04](../Chapter_04) Chapter 05 [Chapter 06 ☛](../Chapter_06)

[Home](https://github.com/adobrich/CppPrimer)
