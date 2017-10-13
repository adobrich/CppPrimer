# Chapter Four Answers

<a name="Section_4.1.2">Section 4.1.2</a>
---
### Exercise 4.1

Multiplication and division have the same precedence, which is higher than that of addition, so these will be evaluated first. Since expressions are left associative the multiplication will be evaluated first, then the division finally the addition; so the expression could be rewritten as `(5 + ((10 * 20)/2))` which evaluates to 105.

### Exercise 4.2

> (a)

The dot `.` operator has higher precedence than the dereference `*` operator.

`* (vec.begin())`

> (b)

Same as above with addition evaluated last.

`(* (vec.begin())) + 1`

<a name="Section_4.1.3">Section 4.1.3</a>
---
### Exercise 4.3

I believe this to be a fair trade-off. I would imagine that if your expression depended upon a certain execution order then it is probably not the correct expression to use, perhaps it would be more meaningful to split it into two expressions for example. Any expression that modifies the same object multiple times is probably in error.

### [Exercise 4.4](exercise_04.cpp)

Division, multiplication and modulo (`%`) all have the same precedence, which is higher than that of addition. Since arithmetic operators are left associative we group starting from the left as below:
```cpp
((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
```
Which outputs: 91

<a name="Section_4.2">Section 4.2</a>
---
### Exercise 4.5

> (a)

```
= ((-30) * 3) + (21 / 5)
= -90 + 4
= -86
```
*Note: integer division truncates the fractional component.*

> (b)

```
= (-30) + ((3 * 21) / 5))
= -30 + 12
= -18
```

> (c)

```
= ((30 / 3) * 21) % 5
= 210 % 5
= 0
```

*Modulo note: 5 goes into 210 42 times with zero remainder hence the result is zero.*

> (d)

```
= (((-30) / 3) * 21) % 4
= -210 % 4
= -2
```

*Modulo note: 4 goes into -210 52 with 2 remaining (ie. 52 * 4 = 208, 2 shy of 210).*

### [Exercise 4.6](exercise_06.cpp)

```cpp
// if intValue % 2 = 0 the value is even otherwise
// it's odd. See link above for example usage
intValue % 2;
```

### Exercise 4.7

An overflow occurs when a computed value is outside the range which the type can represent.

```cpp
// unsigned char (2^8 - 1) has a range of {0, 1, 2 ... 255}
// -1 is impossible, result is therefore 255.
unsigned char firstMistake = 0;
--firstMistake;

// short (2^16 - 1) has a range of {-32768, -32767, 32766 ... 32767}
// 655340 is impossible, result is therefore -5536.
short secondMistake = 30000;
short multiplier = 2;

secondMistake *= multiplier;

// int (2^32 - 1) has a range of
// {-2147483648, -2147483647 -2147483646 ... 2147483647}
// 2147483902 is impossible, result is therefore -2147483394.
int thirdMistake = 2147483647;

thirdMistake += firstMistake;
```

<a name="Section_4.3">Section 4.3</a>
---
### Exercise 4.8

Operands for logical `AND` will be evaluated from left to right, the right operand will only be evaluated *if* the left operand is *true*.

Operands for logical `OR` will also be evaluated from left to right, the right operand will only be evaluated *if* the left operand is *false*.

*Both* operands for the equality operator will be evaluated. Again, these will be evaluated left to right. The result of the left operand will be compared with the result of the right.

### Exercise 4.9

The first operand is true if `cp` is not a `nullptr`, the second operand is true if the dereferenced value of `cp` is not empty or zero. Due to the nature of the logical `AND` operator this code will not attempt to dereference a null pointer (it will short-circuit after failing the first evaluation).
Since `cp` is a valid pointer (true) and `*cp` = `H` (true) the result of this statement is true.

### Exercise 4.10

```cpp
int userInput;
while (cin >> userInput && userInput != 42)
```

### Exercise 4.11

```cpp
auto result = a > b &&
              b > c &&
              c > d;
```

### Exercise 4.12

Since the less than `<` operator has higher precedence than the inequality `!=` operator, `j < k` will be evaluated first making the statement `i != boolean_value`. The boolean value will be converted to either 1 or 0 respectively depending on whether `j` is less than `k` or not.
Possible outcomes are:

If `j < k` is true (1), the statement is true if `i` does not equal 1, it is false otherwise.

if `j < k` is false (0), the statement is true if `i` does not equal 0, it is false otherwise.

<a name="Section_4.4">Section 4.4</a>
---
### Exercise 4.13

> (a)

3.5 will be narrowed to 3 since `i` is an`int`, `d` is then assigned the value of `i`:
```
i = 3
d = 3.0
```

> (b)

`d` is assigned the value of 3.5, `i` is then assigned the value of `d`, which will be narrowed to 3 since it's an `int`.
```
i = 3
d = 3.5
```
*Note: Assignment is __right__ Associative*

### Exercise 4.14

`if (42 = i)` is invalid and will not compile. 42 is not modifiable lvalue, it is a literal which is an rvalue.

`if (i = 42)` This condition assigns the value of 42 to `i`, then tests the result of the assignment. If `i` is nonzero then the condition is true.

### Exercise 4.15

`pi = 0` creates a null pointer. Trying to assign a null pointer to an `int` is illegal. We can fix this in an ugly way, by combining the assignment of `pi` with an expression like so:
```cpp
dval = ival = (pi = 0) != nullptr;
```
By adding the inequality operator and parenthesising the assignment of `pi` we can return an integer value that `ival` can use while still making the same assignment intended by the original code. We know `pi = 0` is a `nullptr` so by adding the condition  `!= nullptr` the expression will return `0` which will be assigned to `ival`, and `dval` respectively.

A better solution would be to use the code below; the intent is clear, there is no head scratching to work out what's going on.

```cpp
double dval = 0.0;
int ival = 0;
int* pi = nullptr;
```

### Exercise 4.16

> (a)

I would assume that the intent of this condition is to check if the newly assigned pointer `p` is null or not. Currently the code does not do this. Since assignment has low precedence `p` is actually assigned the result of `getPtr() != 0`, which if the function returns anything that is non-zero will be true. To fix this code we simply have to parenthesise the assignment of `p` so it is evaluated first.
```cpp
if ((p = getPtr()) != 0)
```

> (b)

In this case I assume the intent to be to compare `i` with the integer value 1024. This code is instead assigning 1024 to `i`. This will always return true.
To fix this code we just have to change the assignment operator to an equality operator.

```cpp
if (i == 1024)
```

<a name="Section_4.5">Section 4.5</a>
---
### Exercise 4.17

The *prefix* increment operator will increment the object and return its new value.
The *postfix* increment operator will increment the object but instead return a copy of the original unmodified object as shown in the example below.
```cpp
int i = 0;

// Increments i and returns the new value
cout << ++i << endl;  // Prints 1

// Increments i but returns a copy of i before the change
cout << i++ << endl;  // Prints 1

// Current value of i
cout << i << endl;    // Prints 2
```

### Exercise 4.18

If we were to use the *prefix* increment operator we would skip the first element in the vector and the last run through the `while` loop would attempt to dereference one past the end of the vector, which will likely cause the program to crash.

### Exercise 4.19

> (a)

This expressions first tests if `ptr` is not null, if true it then checks if the value to which `ptr` points to is non-zero then increments `ptr`. This expression returns true if `ptr` is not null and `ptr`s value is non-zero, it is false otherwise.

> (b)

This expression first checks if `ival` is non-zero (using the original value) then increments the value, if the original value is non-zero it then checks if the new value of `ival` is non-zero. This expression returns true if both `ival` and the incremented `ival` are non-zero, false otherwise.

> (c)

Unlike the previous two expressions this one uses the `<=` operator. This operator does not guarantee the left hand operand will be evaluated first. To fix this we could use the following:
```cpp
vec[ival] <= vec[ival + 1]
```
The above expression doesn't rely on a particular evaluation order. Left or right hand operand can be evaluated first.

<a name="Section_4.6">Section 4.6</a>
---
### Exercise 4.20

> (a)

`iter` is (postfix) incremented and now points to the next `string` in the `vector`. A copy of the previous `iter` is dereferenced yielding the original `string` `iter` pointed to.

> (b)

This expression is in error. If we dereference `iter` it returns a `string`, trying to increment a string makes no sense, and is illegal.
> (c)

Illegal since there is no semi colon but if there was, the dot `.` operator has higher precedence than the dereference `*` operator so this expression is in error since pointers done have the `empty()` member function.

> (d)

Checks if the `string` currently pointed to by `iter` is empty. Returns true if it is, false otherwise.

> (e)

Both the (prefix) increment `++` and dereference `*` operators have the same precedence but they are right associative, therefore, the above is in error since we cant increment a `string`.

> (f)

First checks if the string `iter` points to is empty, then increments the iterator. Returns true if original string `iter` points to is empty, false otherwise.

<a name="Section_4.7">Section 4.7</a>
---
### [Exercise 4.21](exercise_21.cpp)

### Exercise 4.22

[Exercise 4.22a](exercise_22a.cpp) (using conditional statements)

[Exercise 4.22b](exercise_22b.cpp) (using `if` statements)

Both of these examples are easy to read, provided you understand how ternary operators work. If I had never read this book I would probably still understand what the if/else statements were doing (since they're basically written in plain English), I would likely struggle with the ternary operators. For this reason I would suggest if/else statements are easier to understand.

### Exercise 4.23

Since the addition and equality operators have higher precedence than the conditional `?:` operator the code as shown could also be written as:
```cpp
string pl = (s + s[s.size() - 1]) == 's' ? "" : "s";
```

It is trying to compare a `string` to a `char` (`"wordd" == 's'`).
To fix this we simply parenthesise the conditional code
```cpp
string pl = s + (s[s.size() - 1]) == 's' ? "" : "s");
```

### Exercise 4.24

First lets understand how it works being right associative.
Considering the original code:
```cpp
finalgrade = (grade > 90) ? "High pass" : (grade < 60) ? "fail" : "pass";
```
Associativity rules determine which operator is evaluated first when two operators of equal precedence are adjacent to each other. As noted the conditional operator is right associative, meaning it is evaluated from right to left like so:

```cpp
finalgrade = ((grade > 90) ? "High pass" : ((grade < 60) ? "fail" : "pass"));
```
The result of the right most conditional operator is used as the fail statement for the left hand conditional statement. As an example if the value of `grade` was `80` the expression would reduce to this:

```cpp
finalgrade = (grade > 90) ? "High pass" : "pass";
```

The final result would obviously be `pass`.

If the conditional statement was left associative it would be evaluated like so:

```cpp
finalgrade = ((grade > 90) ? "High pass" : (grade < 60)) ? "fail" : "pass";
```
This code will not compile since the expressions for true/false branches in the first conditional statement are not compatible/convertible types; they would both need to be of the same or valid convertible type. Even if this code would compile the result would be incorrect. If `grade` was > 90 the expression would reduce like so:

```cpp
finalgrade = "High pass" ? "fail" : "pass";
```
The result would be `fail` since an initialised `string` is always true.

<a name="Section_4.8">Section 4.8</a>
---
### Exercise 4.25

The bitwise `NOT` operator `~` has highest precedence and will be evaluated first, so we simply flip all bits to their opposite state:

```
Original bit pattern: 01110001
New bit pattern:      10001110
```
In the process of flipping those bits `char` is promoted to `int`, so the final bit pattern for `~'q'` is :
```
11111111 11111111 11111111 10001110
```
Now we shift those bits left 6:
```
11111111 11111111 11100011 10000000
```

The end result in (unsigned) integer representation is `4294960000`.

### Exercise 4.26

Since the criteria for the quiz example required a *minimum* of 30 bits, a data type of 32 bit length is required. `unsigned int` is only *guaranteed* to have 16 bits, but is commonly 32. For those edge cases where the machine does not support 32 bit ints, the program will not function correctly. Any bits shifted past 16 (such as 27 in the quiz example) will be shifted out of range and be discarded. Only the available 16 bits will be accessible.

### Exercise 4.27

> (a)

Below are the bit patterns for the two variables and the resulting bit pattern of the expression.
```
ul1       = 00000000 00000000 00000000 00000011
ul2       = 00000000 00000000 00000000 00000111
ul1 & ul2 = 00000000 00000000 00000000 00000011
```
Result is 3.

> (b)

Below are the bit patterns for the two variables and the resulting bit pattern of the expression.
```
ul1       = 00000000 00000000 00000000 00000011
ul2       = 00000000 00000000 00000000 00000111
ul1 | ul2 = 00000000 00000000 00000000 00000111
```
Result is 7.

> (c)

Result is `true` since both `ul1` and `ul2` are non-zero.

> (d)

Result is `true` since `ul1` is non-zero. `ul2` isn't evaluated since the statement short circuits.

<a name="Section_4.9">Section 4.9</a>
---
### [Exercise 4.28](exercise_28.cpp)

Sample output:
```
Size of nullptr:     8 byte(s).
Size of bool:        1 byte(s).
Size of char:        1 byte(s).
Size of wchar_t:     4 byte(s).
Size of char16_t:    2 byte(s).
Size of char32_t:    4 byte(s).
Size of short:       2 byte(s).
Size of int:         4 byte(s).
Size of long:        8 byte(s).
Size of long long:   8 byte(s).
Size of float:       4 byte(s).
Size of double:      8 byte(s).
Size of long double: 16 byte(s).
```

### Exercise 4.29

looking at the previous exercise we can see that an `int` is 4 bytes, therefore and `array` of 10 ints would be 40 bytes, so the first statement would reduce to:
```cpp
cout << 40/4 << endl;
```
Which results in 10.

The second statement is a little different. `sizeof(p)` actually returns the size of a pointer, not the size of the object to which it points. From the previous exercise we can see that a pointer is 8 bytes, therefore the second statement would reduce to:
```cpp
cout << 8/4 << endl;
```
Which results in 2, though keep in mind these results may differ depending on the system the program is run.

### Exercise 4.30

> (a)

`sizeof` has higher precedence than binary `+`
```cpp
(sizeof x) + y
```

> (b)

Both member selector and subscript have higher precedence than `sizeof`
```cpp
sizeof(p->mem[(i)])
```
> (c)

`sizeof` has higher precedence than `<`.
```cpp
(sizeof a) < b
```

> (d)

Function calls have higher precedence than `sizeof`
```cpp
sizeof(f())
```

<a name="Section_4.10">Section 4.10</a>
---
### [Exercise 4.31](exercise_31.cpp)

The main reason for using prefix increment/decrement is for clarity. The intent of the program is easier to understand since the evaluations and results are immediate and obvious. Postfix increment/decrement update the value immediately but return a copy of the unchanged value; this has a very slight performance cost and can be harder to follow.
In the code example the use of prefix or postfix increment doesn't matter, the resulting vector will be the same. The reason for this is that the `for` loop header and the body are separated, they are not the same statement, so by the time we update `ivec[ix] = cnt;` `ix` and `cnt` are the incremented/decremented values.

### Exercise 4.32

Both conditions do the same thing as detailed below.

Init-statement:
```cpp
int *ptr = ia // Sets ia to the first element in the array
```
```cpp
int ix = 0 // Sets ix to the first index of the array
```

Condition:
```cpp
ix != size // True while ix is not equal to array size
```
```cpp
ptr != ia+size // True while ptr is not equal to memory address of one past the end of the array
```
*Note: Addition of and array and an integer (`n`) results in the memory address of the `n`'th element.*

Increment
```cpp
++ix // Increment the index
```
```cpp
++ptr // Advance the pointer
```

### Exercise 4.33

Since the conditional operator has higher precedence than the comma operator, the previous expression can be shown like so:
```cpp
((someValue ? ++x, ++y : --x), --y)
```
The first valid conditional statement `condition ? expression : expression` is used, hence `, --y` is excluded from the conditional expression.

If `someValue` is true, `x` is incremented, `y` is incremented, then decremented (outside of the conditional statement) and returned.
If `someValue` is false, `x` is decremented, then `y` is decremented (outside of the conditional statement) and returned.

<a name="Section_4.11.1">Section 4.11.1</a>
---
### Exercise 4.34

> (a)

If `fval` is 0.0 it is converted to `false` otherwise it is converted to `true`.

> (b)

`ival` is converted to `float`, the result of `fval` and `ival` is converted to `double`.

> (c)

`cval` is converted to `int`, the result of `ival * cval` is converted to `double`.

<a name="Section_4.11.3">Section 4.11.3</a>
---
### Exercise 4.36

```cpp
i *= static_cast<int>(d);
```

### Exercise 4.37

> (a)

`void` can hold any non-const object.
```cpp
pv = const_cast<string*>(ps);
```

> (b)

Directly cast to `int`.
```cpp
i = static_cast<int>(*pc);
```

> (c)

Cast as `void*` retrieve as `double`.
```cpp
pv = static_cast<void*>(&d);
```

> (d)

Reinterpret `void*` as `char*`.
```cpp
pc = reinterpret_cast<char*>(pv);
```

### Exercise 4.38

Due to operator precedence the integer division will occur first, the result of this will then be converted to type `double`. This results in `slope` being assigned a narrowed result.

---
[☚ Chapter 03](../Chapter_03) Chapter 04 [Chapter 05 ☛](../Chapter_05)

[Home](https://github.com/adobrich/CppPrimer)
