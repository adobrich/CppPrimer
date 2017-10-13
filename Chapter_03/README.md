# Chapter Three Answers

<a name="Section_3.1">Section 3.1</a>
---
### Exercise 3.1

[Exercise 3.1a](exercise_01a.cpp) (Rewrite of exercise [1.9](../Chapter_01/exercise_09.cpp) with `using` declarations)

[Exercise 3.1b](exercise_01b.cpp) (Rewrite of exercise [1.10](../Chapter_01/exercise_10.cpp) with `using` declarations)

[Exercise 3.1c](exercise_01c.cpp) (Rewrite of exercise [1.11](../Chapter_01/exercise_11.cpp) with `using` declarations)

[Exercise 3.1d](exercise_01d.cpp) (Rewrite of exercise [2.41a](../Chapter_02/exercise_41a.cpp) with `using` declarations)

[Exercise 3.1e](exercise_01e.cpp) (Rewrite of exercise [2.41b](../Chapter_02/exercise_41b.cpp) with `using` declarations)

[Exercise 3.1f](exercise_01f.cpp) (Rewrite of exercise [2.41c](../Chapter_02/exercise_41c.cpp) with `using` declarations)

[Exercise 3.1g](exercise_01g.cpp) (Rewrite of exercise [2.41d](../Chapter_02/exercise_41d.cpp) with `using` declarations)

[Exercise 3.1h](exercise_01h.cpp) (Rewrite of exercise [2.41f](../Chapter_02/exercise_41f.cpp) with `using` declarations)

<a name="Section_3.2.2">Section 3.2.2</a>
---
### [Exercise 3.2](exercise_02.cpp)

[Exercise 3.2a](exercise_02a.cpp) Read from standard input a **line** at a time.

[Exercise 3.2b](exercise_02b.cpp) Read from standard input a **word** at a time.

### Exercise 3.3

The `string` input operator trims leading and trailing white space and returns only the characters between. For example the if the user entered the `string`
```
     There are 5 spaces at the start of this line and one at the end 
```
 the input operator would trim the white-space from the beginning of the string (the first five spaces), then read characters until it reached the next white-space. The result of the first read would be `There`. Basically `string` input is using white space as a delimiter.
 
The `getline()` function will instead retain all white-space and use a new line as it's delimiter. Using the example input above, the `getline()` function reads in each character (white-space included) until it reaches a newline character. So after the first read the output would be
```
     There are 5 spaces at the start of this line and one at the end 
```

### Exercise 3.4

[Exercise 3.4a](exercise_04a.cpp) Check equality or largest string.

[Exercise 3.4b](exercise_04b.cpp) Check length equality or longest string.

### Exercise 3.5

[Exercise 3.5a](exercise_05a.cpp) Concatenated strings, no space.

[Exercise 3.5b](exercise_05b.cpp) Concatenated strings, with spaces.

<a name="Section_3.2.3">Section 3.2.3</a>
---
### [Exercise 3.6](exercise_06.cpp)

### Exercise 3.7

If we were to change from `auto&` to `char&` the program would work as expected since the deduced type from `auto` is `char` anyway. If we assume the question is asking to drop the `&` all together then the program would not work as expected. If the reference was dropped, the original string would never be modified, instead the local variable inside the range `for` would be changed to 'X' then overwritten on the next iteration. The original string would be printed having never been altered.

[Exercise 3.7](exercise_07.cpp) Exercise 3.6 with revised range `for` that does essentially does nothing.

### Exercise 3.8

[Exercise 3.8a](exercise_08a.cpp) Rewrite of exercise [3.6](exercise_06.cpp) using a `while` loop.

[Exercise 3.8b](exercise_08b.cpp) Rewrite of exercise [3.6](exercise_06.cpp) using a traditional `for` loop.

A range `for` loop is by far the cleanest solution to these exercises. There are no extra variables to declare or increment like in the `while` loop and it is easier to read than the traditional `for` loop.

### Exercise 3.9

This code is valid in that the compiler will not complain, it is functionally incorrect though. A default initialised string is an empty string `""` it has no content at index 0. Accessing an index of an empty string is undefined.

### [Exercise 3.10](exercise_10.cpp)

### Exercise 3.11

Legal. `c` is a `const char&`. So long as the body of the rage `for` doesn't try to modify `c` it will be legal.

<a name="Section_3.3.1">Section 3.3.1</a>
---
### Exercise 3.12

> (a)

Legal, creates a `vector` which contains a default initialised `vector` of type `int`.

> (b)

Illegal, like trying to fit the star shape in the round hole; the `vectors` must have the same type to perform copy initialisation.

> (c)

Legal, constructs the vector using the class constructor resulting in a vector with 10 string elements initialised to "null".

### <a name="exercise_3.13">Exercise 3.13</a>

> (a)

Empty vector.

> (b)
Uses the class constructor to construct a `vector` with 10 `ints` default initialised to 0.

> (c)

Uses the class constructor to construct a `vector` with 10 `ints` initialised to 42.

> (d)

Uses list initialisation to create a `vector` with one 'int` element initialised to 10.

> (e)

Uses list initialisation to create a `vector` with two `int` elements initialised to 10 and 42 respectively.

> (f)

Uses list initialisation to create a `vector` with 10 default initialised (empty) `strings`.

> (g)

Uses list initialisation to create a `vector` with 10 `string` elements initialised to "hi".

<a name="Section_3.3.2">Section 3.3.2</a>
---
### [Exercise 3.14](exercise_14.cpp)

### [Exercise 3.15](exercise_15.cpp)

<a name="Section_3.3.3">Section 3.3.3</a>
---
### [Exercise 3.16](exercise_16.cpp)

### [Exercise 3.17](exercise_17.cpp)

### Exercise 3.18

The program above is not legal. `ivec` is an empty `vector` it has no element at index 0. Attempting to access an out of range index is undefined.
To fix the problem we have three logical options. We can list initialise the `vector`
```cpp
vector<int> ivec{42};
```
We can initialise the `vector` with one default initialised element
```cpp
vector<int> ivec(1);
ivec[0] = 42;
```
Or we could use the member function `push_back`
```cpp
vector<int> ivec;
ivec.push_back(42);
```
List initialisation is my preferred method for this example.

### Exercise 3.19

Create an empty `vector` and populate it using the `push_back` member function
```cpp
vector<int> ivec;
for (int i = 0; i < 10; ++i)
    ivec.push_back(42);
```
list initialise the `vector`
```cpp
vector<int> ivec{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
```
Use the class constructor
```cpp
vector<int> ivec(10, 42);
```
The preferred method is to use the class constructor. This method is perfectly suited to the task, it is compact, efficient and less error prone than typing each value individually.

### Exercise 3.20

[Exercise 3.20a](exercise_20a.cpp) (Sum of adjacent elements)

[Exercise 3.20b](exercise_20b.cpp) (Sum of first and last, second and second-to-last, and so on.)

<a name="Section_3.4.1">Section 3.4.1</a>
---
### [Exercise 3.21](exercise_21.cpp)

### [Exercise 3.22](exercise_22.cpp)

### [Exercise 3.23](exercise_23.cpp)

<a name="Section_3.4.2">Section 3.4.2</a>
---
### Exercise 3.24

[Exercise 3.24a](exercise_24a.cpp) (Rewrite of exercise [3.20a](exercise_20a.cpp) using iterators)

[Exercise 3.24b](exercise_24b.cpp) (Rewrite of exercise [3.20b](exercise_20b.cpp) using iterators)

### [Exercise 3.25](exercise_25.cpp)

### Exercise 3.26

Let's first understand how and why `mid = beg + (end - beg) / 2;` works, then work out why `min = (beg + end) / 2;` was not used in this solution.
Both `beg` and `end` are iterators of type `int`. Iterators work much like pointers; `beg` points to the first element in the vector, `end` points to 'one-past-the-end'. With this information we can draw a diagram to represent a vector with 5 elements and mark where `beg` and `end` are. This should help us understand what's going on.
```cpp
// Below is a representation of the following vector and beg / end iterators
vector<int> ivec {5, 6, 7, 8, 9};
beg = ivec.begin();
end = ivec.end();

// +---+---+---+---+---+---+
// | 5 | 6 | 7 | 8 | 9 |   |
// +---+---+---+---+---+---+
//   ^                   ^
//   b                   e
//   e                   n
//   g                   d
```

Now what happens when we minus `beg` from `end`? When we perform this type of arithmetic on iterators (an iterator minus and iterator) the returned type is **not** an iterator it is instead a `difference_type`, that is, a numerical value which is the distance between 2 iterators in the supplied container. In the case of the vector above `beg` represents the first element, `end` represents the sixth element (one-past-the-end) so our definition basically reduces to `mid = beg + (6 - 1) / 2` or `mid = beg + 2` (**not** +2.5 since integer division drops the fractional component). Adding or subtracting a numerical type from an iterator means increment/decrement the iterator by the numerical value given. In this case, advance beg by 2 places.

```cpp
// +---+---+---+---+---+---+
// | 5 | 6 | 7 | 8 | 9 |   |
// +---+---+---+---+---+---+
//   ^       ^           ^
//   b       m           e
//   e       i           n
//   g       d           d
```
That is how we end up with `mid` at the midpoint of the vector.
If we try to use the second option `mid = (beg + end) / 2;` we can immediately see some issues.
Both `beg` and `end` are iterators, addition of iterators is not legal.  It doesn't make sense to add two iterators together since they're just pointers to an address in memory, it wouldn't provide any useful information (subtraction *does* make sense since it will produce a type based distance between the two iterators as we've seen above). Even if `beg + end` was legal, like `end - beg` it wouldn't produce an iterator. So *if* this definition was legal, `mid` would be a number instead of an iterator (pointer) to the midpoint of the vector.

<a name="Section_3.5.1">Section 3.5.1</a>
---
### <a name="exercise_27">Exercise 3.27</a>

> (a)

Illegal, `buf_size` is not a constant expression.

> (b)

Legal, no variables are used in calculation so it is constant.

> (c)

Legal **if** `txt_size()` is a constant expression, illegal otherwise.

> (d)

Illegal, there is no space left in the array for the null (`\0`) character.

*Side note: Both gcc and clang will compile the above array definitions without warning or error since they both allow variable length arrays, via extensions. Add `-pedantic` to your compile options to ensure the warnings for variable length arrays are shown. Remember, it's better to not use these extensions for the sake of portability.*

### Exercise 3.28

`sa` contains 10 default initialised `strings` (10 empty `strings` `""`).

`ia` contains 10 default initialised `ints` (10 `ints` set to `0`) since it has been defined outside a function.

*`string` is a library type and by default initialises to `""` regardless of where it is defined.*

`sa2` contains 10 default initialised `strings` (10 empty `strings` `""`).

`ia2` contains 10 undefined `ints` since it has been defined inside a function.

### Exercise 3.29

- Dimension (size) of the `array` must be known at compile time (refer note at the end of <a href="#exercise_27">exercise 3.27</a>).
- Dimension of the `array` cannot be changed once created.
- Memory for the complete `array` will be allocated when it is declared even if you don't end up using all the elements.
- `arrays` don't have the same ease of use that vectors provide.

<a name="Section_3.5.2">Section 3.5.2</a>
---
### Exercise 3.30

The index is out of sync with the elements of the `array`. `array` indexes start at zero, not one as in the above program.

`ia` prior to for loop:
```
index:      0   1   2   3   4   5   6   7   8   9
          +---+---+---+---+---+---+---+---+---+---+
elements: | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
          +---+---+---+---+---+---+---+---+---+---+
```

After the first loop through the `for`:
```
index:      0   1   2   3   4   5   6   7   8   9
          +---+---+---+---+---+---+---+---+---+---+
elements: | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
          +---+---+---+---+---+---+---+---+---+---+
                ^
                i
                x
```

The last loop causes a buffer overflow since `ix` = 10 and the array index only goes to 9:
```
index:      0   1   2   3   4   5   6   7   8   9
          +---+---+---+---+---+---+---+---+---+---+---+
elements: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |   |
          +---+---+---+---+---+---+---+---+---+---+---+
                                                    ^
                                                    i
                                                    x
                                             BUFFER OVERFLOW
```

### [Exercise 3.31](exercise_31.cpp)

### Exercise 3.32

[Exercise 3.32a](exercise_32a.cpp) Copy from one array to another.

[Exercise 3.32b](exercise_32b.cpp) Rewrite using `vectors`

### Exercise 3.33

If the `array` was not initialised, each element would then be default initialised. Since the `array` is defined within the main function this would mean each element would have an undefined value.

Output example:
```
index:       0    1   2   3      4      5      6      7        8         9    10
          +-----+---+---+---+---------+---+---------+---+------------+-------+---+
elements: | 142 | 0 | 0 | 0 | 4196592 | 0 | 4196160 | 0 | 1388771872 | 32766 | 0 |
          +-----+---+---+---+---------+---+---------+---+------------+-------+---+
```

<a name="Section_3.5.3">Section 3.5.3</a>
---
### Exercise 3.34

This code increments `p1` by the difference between `p2` and `p1`. Any legal value for `p1` and `p2` will produce a legal outcome. 
Some examples below.
```cpp
// Example array
int fiveInts[] = {1, 2, 3, 4, 5};
int* p1 = begin(fiveInts);
int* p2 = end(fiveInts);

// +---+---+---+---+---+---+
// | 1 | 2 | 3 | 4 | 5 |   |
// +---+---+---+---+---+---+
//   ^                   ^
//   p                   p
//   1                   2

// Now let's increment p1 as per the exercise
p1 += p2 - p1;  // Same as p1 += 6 - 1

// +---+---+---+---+---+---+
// | 1 | 2 | 3 | 4 | 5 |   |
// +---+---+---+---+---+---+
//                       ^
//                       p
//                       1
//                       &
//                       p
//                       2

// One more example
p1 -= 4;
p2 -= 2;

// +---+---+---+---+---+---+
// | 1 | 2 | 3 | 4 | 5 |   |
// +---+---+---+---+---+---+
//       ^       ^
//       p       p
//       1       2

// Now let's increment p1 as per the exercise
p1 += p2 - p1;  // Same as p1 += 4 - 2

// +---+---+---+---+---+---+
// | 1 | 2 | 3 | 4 | 5 |   |
// +---+---+---+---+---+---+
//               ^
//               p
//               1
//               &
//               p
//               2
```
As we can see, whatever the starting value, after we increment `p1` as shown in the exercise both pointers end up pointing to the same element.

### [Exercise 3.35](exercise_35.cpp)

### Exercise 3.36

[Exercise 3.36a](exercise_36a.cpp) Array comparison.

[Exercise 3.36b](exercise_36b.cpp) Vector comparison.

<a name="Section_3.5.4">Section 3.5.4</a>
---
### Exercise 3.37

This program will print:
```
h
e
l
l
o
```

However, `ca` doesn't have a terminating `null` character so the `while` loop will not end where we expect. It will likely continue to print whatever is in memory until it finds a `null` character.
As a test let's assign another variable after the `while` loop.
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
const char secretCode[] = {'1', '2', '3', '4', '5'};
```

This program outputs:
```
h
e
l
l
o
1
2
3
4
5
```

Not good. Remember to terminate c-style strings with null characters:
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
```

### Exercise 3.38

If we had two pointers, one to a `string` the other to an `int` what would the outcome of adding these pointers be? No idea. What use would the result serve? No idea. Pointers are just memory addresses, we generally don't know beforehand what the address of a newly created object will be so adding them makes little sense especially since they will be different each time the program is run. Even if we consider a container type like a `vector` for instance. If we had two pointers, each to a different element in the `vector`, what would the purpose be of adding those pointers? Nothing good I imagine. If for example the first pointer was the 'off-the-end' element, and the second was the third element in the `vector`, the resulting addition would no doubt be a memory address well outside the vector and therefore illegal, attempts to dereference such a pointer will likely crash the program.

### Exercise 3.39

[Exercise 3.39a](exercise_39a.cpp) Compare two strings.

[Exercise 3.39b](exercise_39b.cpp) Compare two c-style strings.

### [Exercise 3.40](exercise_40.cpp)

<a name="Section_3.5.5">Section 3.5.5</a>
---
### [Exercise 3.41](exercise_41.cpp)

### [Exercise 3.42](exercise_42.cpp)

<a name="Section_3.6">Section 3.6</a>
---
### Exercise 3.43

[Exercise 3.43a](exercise_43a.cpp) Using `range for`.

[Exercise 3.43b](exercise_43b.cpp) Using subscript.

[Exercise 3.43c](exercise_43c.cpp) Using pointers.

### Exercise 3.44

[Exercise 3.44a](exercise_44a.cpp) (Rewrite of exercise 3.43a above using type alias).

[Exercise 3.44b](exercise_44b.cpp) (Rewrite of exercise 3.43b above using type alias).

[Exercise 3.44c](exercise_44c.cpp) (Rewrite of exercise 3.43c above using type alias).

### Exercise 3.45

[Exercise 3.45a](exercise_45a.cpp) (Rewrite of exercise 3.43a above using `auto`).

[Exercise 3.45b](exercise_45b.cpp) (Rewrite of exercise 3.43b above using `auto`).

[Exercise 3.45c](exercise_45c.cpp) (Rewrite of exercise 3.43c above using `auto`).

---
[☚ Chapter 02](../Chapter_02) Chapter 03 [Chapter 04 ☛](../Chapter_04)

[Home](https://github.com/adobrich/CppPrimer)
