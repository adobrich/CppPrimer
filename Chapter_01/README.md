# Chapter One Answers
<a name="Section_1.1.1">Section 1.1.1<a>
---
### [Exercise 1.1](exercise_01.cpp)

[GCC Documentation: 3.3 Compiling C++ Programs](http://gcc.gnu.org/onlinedocs/gcc/Invoking-G_002b_002b.html#Invoking-G_002b_002b)

### [Exercise 1.2](exercise_02.cpp)

```sh
$ ./exercise_01
$ echo $?
$ 0

$ ./exercise_02
$ echo $?
$ 255
```
<a name="Section_1.2">Section 1.2<a>
---
### [Exercise 1.3](exercise_03.cpp)

### [Exercise 1.4](exercise_04.cpp)

### [Exercise 1.5](exercise_05.cpp)

### Exercise 1.6

```cpp
int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1;
              << " and " << v2;
              << " is " << v1 + v2 << std::endl;
    return 0;
}
```
This program is not legal as the first `;` character in the `std::cout` statement ends the statement. The two lines that follow are not part of the cout statement and are therefore not legal.

<a name="Section_1.3">Section 1.3<a>
---
### Exercise 1.7

```cpp
/*
 * This next comment breaks the program
 * /* Can't have comment pairs within comment pairs */
 */
int main()
{
    return 0;
}
```

Compiler output:
```
commentTest.cpp:4:3: error: expected unqualified-id before ‘/’ token
  */
   ^
commentTest.cpp:4:3: error: expected constructor, destructor, or type conversion before ‘/’ token
```

### Exercise 1.8

First statement is legal and outputs:

`/*`

Second statement is also legal and outputs:

`*/`

Third statement is illegal but can be fixed by inserting a closing `"` just before the `;` as shown below:

```cpp
std::cout << /* "*/" */";
```
This outputs:

` */`

The final line is legal and outputs:

` /* `

The final output of this program with the fix made to the third statement is:

`/**/ */ /* `

<a name="Section_1.4.1">Section 1.4.1<a>
---
### [Exercise 1.9](exercise_09.cpp)

### [Exercise 1.10](exercise_10.cpp)

### [Exercise 1.11](exercise_11.cpp)

<a name="Section_1.4.2">Section 1.4.2<a>
---
### Exercise 1.12

This loop sums the values from -100 to 100 inclusive resulting in zero as per below:
```
sum = -100   at i = -100
sum = -199   at i = -99
sum = -297   at i = -98
...
sum = -5050  at i = 0
...
sum = -199   at i = 98
sum = -100   at i = 99
sum = 0      at i = 100
```

### Exercise 1.13

[Exercise 1.13a](exercise_13a.cpp) (Rewrite of 1.09 using `for` loop)

[Exercise 1.13b](exercise_13b.cpp) (Rewrite of 1.10 using `for` loop)

[Exercise 1.13c](exercise_13c.cpp) (Rewrite of 1.11 using `for` loop)

### Exercise 1.14

There aren't really any advantages or disadvantages between the two loops, however, there are situations where one might be more useful, or the intent of the code would be clearer if one was chosen over the other. As a general rule `for` loops are better suited to situations where the number of iterations is known, whereas, `while` loops shine when the number of iterations is unknown.

### Exercise 1.15

Example of a *syntax error*: Missing closing bracket `)` for main.
```cpp
int main(
{
    return 0;
}
```
Compiler output:
```
fail.cpp:1:9: error: cannot declare ‘::main’ to be a global variable
 int main(
         ^
fail.cpp:3:5: error: expected primary-expression before ‘return’
     return 0;
     ^~~~~~
fail.cpp:3:5: error: expected ‘}’ before ‘return’
fail.cpp:3:5: error: expected ‘)’ before ‘return’
fail.cpp:4:1: error: expected declaration before ‘}’ token
 }
 ^
```

Example of a *type error*: Assigning a `string` to an `int`.
```cpp
int main()
{
    int number = "four";

    return 0;
}
```

Compiler output:
```
fail2.cpp: In function ‘int main()’:
fail2.cpp:3:18: error: invalid conversion from ‘const char*’ to ‘int’ [-fpermissive]
     int number = "four";
                  ^~~~~~
```

Example of a *declaration error*: Using a variable that hasn't been declared yet.
```cpp
int main()
{
    int total = notDeclared + 5;
    
    return 0;
}
```

Compiler output:
```
fail3.cpp: In function ‘int main()’:
fail3.cpp:3:17: error: ‘notDeclared’ was not declared in this scope
     int total = notDeclared + 5;
                 ^~~~~~~~~~~
```
<a name="Section_1.4.3">Section 1.4.3<a>
---
### [Exercise 1.16](exercise_16.cpp)
Write your own version of a program that prints the sum of a set of integers read from `cin`.

<a name="Section_1.4.4">Section 1.4.4<a>
---
### Exercise 1.17

If the values are all equal the program will generate a single line of output indicating that '*x* occurs *n* times' where *x* is the number and *n* is the frequency.

If all values are different the program will produce a new line of output, in the same format as before, for each number.

### [Exercise 1.18](exercise_18.cpp)

Program output when all input values are equal and all input is given in a single line:
```
1 1 1 1 1
1 occurs 5 times
```

When input is supplied one-at-a-time:
```
1
1
1
1
1
1 occurs 5 times
```

Program output when all input values are different but still supplied in a single line:
```
1 2 3 4 5
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
```

When input is supplied one-at-a-time:
```
1
2
1 occurs 1 times
3
2 occurs 1 times
4
3 occurs 1 times
5
4 occurs 1 times
5 occurs 1 times
```

### [Exercise 1.19](exercise_19.cpp)
Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

<a name="Section_1.5.1">Section 1.5.1<a>
---
### [Exercise 1.20](exercise_20.cpp)

**Note**: I've stored a copy of the `Sales_item.h` header file in the [include](../include) folder.  I've also put my book data in a `.txt` file named [books.txt](../data/books.txt) located in the [data](../data) directory rather than in the current working directory as suggested in this exercise.

Output:
```
$ ./exercise_20 < ../data/books.txt
0-006-47988-X 1 12.95 12.95
0-006-47988-X 1 12.95 12.95
0-006-47988-X 1 12.95 12.95
0-007-46582-3 4 89.8 22.45
0-006-48612-6 3 57 19
0-007-48384-8 7 227.5 32.5
0-007-11955-0 2 20 10
0-002-24739-9 1 50 50
```

### [Exercise 1.21](exercise_21.cpp)

[Exercise 1.21b](exercise_21b.cpp): Updated to check ISBNs match as per *§ 1.5.2: A first look at member functions.*

### [Exercise 1.22](exercise_22.cpp)

[Exercise 1.22b](exercise_22b.cpp): Updated to check ISBNs match as per *§ 1.5.2: A first look at member functions.*

<a name="Section_1.5.2">Section 1.5.2<a>
---
### [Exercise 1.23](exercise_23.cpp)

### Exercise 1.24

Output:
```
$ ./exercise_23 < ../data/books.txt
3 Transaction(s) for ISBN '0-006-47988-X'
1 Transaction(s) for ISBN '0-007-46582-3'
1 Transaction(s) for ISBN '0-006-48612-6'
1 Transaction(s) for ISBN '0-007-48384-8'
1 Transaction(s) for ISBN '0-007-11955-0'
```

<a name="Section_1.6">Section 1.6<a>
---
### [Exercise 1.25](exercise_25.cpp)

Output:
```
$ ./exercise_25 < ../data/books.txt
0-006-47988-X 3 38.85 12.95
0-007-46582-3 4 89.8 22.45
0-006-48612-6 3 57 19
0-007-48384-8 7 227.5 32.5
0-007-11955-0 2 20 10
0-002-24739-9 1 50 50
```
---
Chapter 01 | [Chapter 02 ☛](../Chapter_02)

[Home](https://github.com/adobrich/CppPrimer)
