# Chapter Two Answers

<a name="Section_2.1.1">Section 2.1.1</a>
---
### Exercise 2.1

An `int` is *at least* as large as a `short` (16 bits), `long` (32 bits) is *at least* as large as an `int`, `long long` (64 bit) is *at least* as large as `long`.
The long and short of it is, only use `long` or `short` if you have a specific need for it.  There isn't much advantage in using a `short` over an `int` since they could be the same size (depending on the system).  Err on the side of caution and use the larger size.  Same goes for `long`.

An `unsigned` type may only represent positive values (including zero), whereas a `signed` type represents an equal spread of positive and negative values, zero being included with the positive. Refer to the number lines below for a visual representation.

Using `char` (8 bits) as an example, a `char` can represent 256 values (2<sup>8</sup> since each binary bit can be in either one of two states, on or off, this creates 256 possible configurations).

<a name="unsigned_char_number_line">`unsigned char` number line: 0 1 2 3 4 5 6 ... 255</a>

<a name="signed_char_number_line">`signed char` number line: -128 ... -3 -2 -1 0 1 2 3 ... 127</a>

Note the max values are one shy of 2<sup>8</sup> since counting starts at zero.

A `float` is a single precision floating point number with a minimum precision of 6 significant digits and is typically represented in one `word` (32 bits). A `double` is typically represented in two `words` (64 bits) and has a minimum precision of 10 significant digits.

### Exercise 2.2

Since the rate will typically be only two significant digits a `float` or a `double` would suffice. Since the rate can't be negative it would make sense to make it an `unsigned` type. If the software was running on a system where resources were tight or there were hardware restrictions, I'd go with a `unsigned float` otherwise a `unsigned double`.

Both principal and payment will also generally only have two significant digits so, `float` or `double` would suffice. Since principal is a negative value (an amount owing) it would need to be a `signed` type whereas the payment will always be positive so an `unsigned` type can be used. Prefer `double` over `float` for the same reasons stated for rate.

**Update:** Prefer to use `double` (`signed`) for all to avoid possible 'wrap around' issues noted in the next exercise.

<a name="Section_2.1.2">Section 2.1.2</a>
---
### Exercise 2.3

`u2 - u` is semantically correct and produces the expected result of 32.
`u - u2` is semantically *incorrect* an `unsigned` value cannot be negative so instead the value 'wraps around'.
If we think about the `unsigned char` [number line](#unsigned_char_number_line) mentioned above we can understand what the result of this operation would be.

Here is the variable `u` on the number line of possible values for an unsigned int.
```
0 1 2 3 4 5 6 7 8 9 10 ... (n - 1)
                    ^
                    u
```
If we try to take 42 from 10 you can clearly see the problem.
```
0 1 2 3 4 5 6 7 8 9 10 ... (n - 1)
^
u
```

We get to zero then have nowhere else to go with 32 left to subtract. This is where the *wrap around* happens.  If we take one more from `u` we end up at `n - 1`, `n` being the maximum size of `unsigned int` (2<sup>32</sup> or 4,294,967,296 on this machine). Therefore our answer to this question must be `n - 32'.

```
0 ... n-34 n-33 n-32 n-31 n-30 n-29 n-28 ... (n - 1)
                ^
                u
```
`i2 - i` is semantically correct and produces the expected value of 32.

`i - i2` is semantically correct (since both `i` and `i2` are `signed` types) and produces the expected result of -32.

`i - u` is not a good idea since the `signed` type will be converted into an `unsigned` type automatically. The result however, will be 0 as expected.

`u - i` is also not a good idea, for the same reasons above, but produces the expected result of 0.

### [Exercise 2.4](exercise_04.cpp)

<a name="Section_2.1.3">Section 2.1.3</a>
---
### Exercise 2.5

| Literal | Type                     |
|  :---:  | :---                     |
|`'a'`    | `char`                   |
|`L'a'`   | `wchar_t`                |
|`"a"`    | `const char*`            |
|`L"a"`   | `const wchar_t*`         |
|`10`     | `int`                    |
|`10u`    | `unsigned int`           |
|`10L`    | `long`                   |
|`10uL`   | `unsigned long`          |
|`012`    | `int` (octal) = 10       |
|`0xC`    | `int` (hexadecimal) = 12 |
|`3.14`   | `double`                 |
|`3.14f`  | `float`                  |
|`3.14L`  | `long double`            |
|`10`     | `int`                    |
|`10u`    | `unsigned int`           |
|`10.`    | `double`                 |
|`10e-2`  | `double` = 0.1           |

Note: string literals (`"a"` & `L"a"`) are noted as being an "array of constant chars" on page 67 but won't be discussed until § 3.5.4.
My IDE ([juCi++](https://github.com/cppit/jucipp)) displays these literals as shown in the table.

### Exercise 2.6

The first declaration works as expected, the second however, is incorrect. Since the number starts with a zero, the compiler is expecting an octal and `09` is not an octal the number nine in octal is actually `011`.

### Exercise 2.7

| Literal                          | Type              | Value                                      |
| :---                             | :---              | :---                                       |
|`"Who goes with F\145rgus?\012"`  | `const char*`     | Who goes with Fergus? (new line)           |
|`3.14e1L`                         | `long double`     | 31.4                                       |
|`1024f`                           | malformed `float` | Error: requires `.` (`1024.f`) to be legal |
|`3.14L`                           | `long double`     | 3.14                                       |

Note: refer to [ASCII table](https://duckduckgo.com/?q=ascii+table) for escaped characters.

### [Exercise 2.8](exercise_08.cpp)

<a name="Section_2.2.1">Section 2.2.1</a>
---
### Exercise 2.9

> (a)

Illegal: `input_value` must be initialised prior to setting it's value via `cin`.
```cpp
int input_value;
std::cin >> input_value;
```
> (b)

Illegal: `i` is list initialised to a type that cannot hold its value.
```cpp
double i = { 3.14 };
```
> (c)

Illegal: `wage` must be defined before it can be assigned to `salary`.
```cpp
double wage = 9999.99, salary = wage;
```
> (d) 

While this one *is* legal, it is probably not correct as the value will be 'narrowed' to 3 since `int`'s don't have a fractional component. Using a double would be better.
```cpp
double i = 3.14;
```

### Exercise 2.10

`global_str` is initialised to an empty string as defined by the `string` class.

`global_int` is defined *outside* the main function so is initialise to the default value, 0.

`local_int` is defined *inside* the main function so its value is undefined.

`local_str` is defined *inside* the main function and its value is initialised to the default value for the `string` class, an empty `string.

<a name="Section_2.2.2">Section 2.2.2</a>
---
### Exercise 2.11

| Statement               | Declaration or Definition        |
| :---:                   | :---                             |
| `extern int ix = 1024;` | Definition - Value is given      |
| `int iy;`               | Definition - Default initialised |
| `extern int iz;`        | Declaration                      |

<a name="Section_2.2.3">Section 2.2.3</a>
---
### Exercise 2.12

> (a)

Not legal. Variable names cannot start with a number.

> (b)

Legal, but not very smart.

> (c)

Not legal. `catch` is a C++ keyword and `-` (hyphen) is an operator. `catch_22` would be acceptable.

> (d)

Not legal. Variable names cannot start with a number.

> (e)

Legal since C++ is case sensitive. Not very smart though.

<a name="Section_2.2.4">Section 2.2.4</a>
---
### Exercise 2.13

`j` equals 100 since the local scope takes precedence. Global `i` is unchanged.

### Exercise 2.14

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
st::cout << i << " " << sum << std::endl;
```

The output of this program would be:

`100 45`

The reason for this is that the `i` used in the `cout` statement is the global value (100). Inside the scope of the `for` loop we define a new variable named `i`, initialise it to zero and use it to update sum.

<a name="Section_2.3.1">Section 2.3.1</a>
---
### Exercise 2.15

> (a)

Legal but will will be 'narrowed' to `1`.

> (b)

Not legal. References must refer to objects.

> (c)

Legal. References the `int` ival.

> (d)

Not legal. References are not objects, they can only refer to objects and as such must be initialised when they are declared.

### Exercise 2.16

> (a)

Legal. `d` is now `3.14159`.

> (b)

Legal. `d` is now `0.0`.

> (c)

Legal, however the value will be 'narrowed'. `i` remains `0`.

> (d)

Legal, however the value will be 'narrowed'. `i` remains `0`.

### Exercise 2.17

Since `ri` is a reference to `i` meaning both variables refer to the same object in memory, any change to either of these variables, changes both. This means that the output of this program would be:
```
10 10
```

<a name="Section_2.3.2">Section 2.3.2</a>
---
### [Exercise 2.18](exercise_18.cpp)

### Exercise 2.19

A reference is **not** an object (but must *refer to* an already existing object) and must be initialised when it is declared. References cannot be reassigned once they are declared.  Once a reference is declared you can access its value as you would a normal variable: `std::cout << myReference << std::endl;`

Pointers **are** objects and instead of referring to an object they 'point' to the object. More specifically they point to the address in memory where the object is stored. Pointers don't need to be initialised when they are declared, they can also be reassigned later. Pointers need to be dereferenced to access their value: `std::cout << *myPointer << std::endl;`
In summary, a reference is more like an alias for an existing object whereas a pointer is a new object that can peek into and manipulate other objects.

### Exercise 2.20

`i` is initialised to 42, the pointer, `p1`, is set to the address of `i`. By dereferencing `p1` the value of `i` is set to `42 * 42` which is 1764.

### Exercise 2.21

> (a)

Illegal. A pointer of type `double` must point to a `double`.

> (b)

Illegal. A pointer must 'point' to the address (in memory) of the object, not the object its self.

> (c)

Legal. Both the pointer and the object are `int`s and the pointer is initialised to the memory address of `i`.

### Exercise 2.22

The first `if` will be true if the pointer is valid and not `null`. The second `if` will be true if the value of the `int` to which `p` points is non zero.

### Exercise 2.23

This is a very ambiguous question. Let's assume that the pointer `p` is supplied in a source file, but the definition of `p` is not visible to us. Since we don't have this source file, to investigate further we'll have to make our own `p`.

To begin with we'll assume that `p` is defined as shown below.
```cpp
#include <iostream>

int main()
{
    int target = 42;
    // p is a pointer to target
    int* p = &target;
    
    if (p)
    {
        std::cout << "Pointer is valid! "
                  << "It's value is: " << *p << std::endl;
    }
    
    return 0;
}
```
If we run this program it will output `Pointer is valid! It's value is: 42`. This works as expected, and we *could* assume success, however, what happens if the pointer is a `nullptr`?. The output would be nothing since a `nullptr` evaluates to 0. Let's update the program to catch this.
```cpp
#include <iostream>

int main()
{
    // p is now a nullptr;
    int* p = nullptr;
    
    if (p)
    {
        std::cout << "Pointer is valid! "
                  << "It's value is: " << *p << std::endl;
    }
    else if (p == nullptr)
    {
        std::cout << "Pointer is null" << std::endl;
    }
    
    return 0;
}
```
Running this program will print `Pointer is null` as expected. Have we succeeded yet? Not quite. What if the memory address the pointer points to is set manually? A quick [search](http://stackoverflow.com/questions/4532000/how-to-assign-pointer-address-manually-in-c-programming-language) shows this is possible.
```cpp
// p is now manually set to a random memory address
int* p = (int *) 0x7fff55550ca4;
```

Running the program with this definition causes a segmentation fault (if there isn't a valid object at that memory address) when it tries to dereference the pointer. So the pointer is valid it just doesn't point to a valid object. Lets try one more thing, what happens if we set a valid pointer, then increment it?  Let's try.
```cpp
#include <iostream>

int main()
{
    int target = 42;
    // p is a pointer to target, like before
    int* p = &target;
    if (p)
    {
        std::cout << "Pointer is valid! "
                  << "It's address is: " << p << std::endl
                  << "It's value is: " << *p << std::endl;
        // now lets increment the pointer and see what happens
        ++p;
        std::cout << "Incremented address is: " << p << std::endl
                  << "Incremented pointer value is: " << *p << std::endl;
    }
    else if (p == nullptr)
    {
        std::cout << "Pointer is null" << std::endl;
    }
    
    return 0;
}
```
If we run this program we get this output:
```
Pointer is valid! It's address is: 0x7ffd44039d54
It's value is: 42
Incremented address is: 0x7ffd44039d58
Incremented pointer value is: 1141087576
```
The program can be run multiple times and the results will be different.
```
Pointer is valid! It's address is: 0x7ffe12bdca44
It's value is: 42
Incremented address is: 0x7ffe12bdca48
Incremented pointer value is: 314427976

Pointer is valid! It's address is: 0x7ffd8257f294
It's value is: 42
Incremented address is: 0x7ffd8257f298
Incremented pointer value is: -2108165480
```
From these examples we can see what pointers point to valid objects and what ones don't by looking at the errors or output they produce. Crashing the program to find out is not a fantastic way to go about it though. Does this really enable us to tell if the object is valid? Probably not. There are other data structures our pointer could point to. These data structures could produce output that looks random or incorrect but still be valid since we don't know what the definition of `p` is. So after all that I would have to conclude that, no, it is not possible to tell with absolute certainty.

### Exercise 2.24

A `void*` can hold the address of any type but the use of a `void*` is limited to the following
- Pointer comparison
- Function parameter or return value
- Assignment to another `void*` type

A `long*` can only hold the address of a `long` object or `nullptr`.

<a name="Section_2.3.3">Section 2.3.3</a>
---
### Exercise 2.25

> (a)

`ip` is a pointer to `int`. It's value is undefined.

`i` is an int. It's value is undefined if declared inside `main()`, `0` if declared globally.

`r` is a reference to `int`. It's value is `i`'s value.

> (b)

`i` is an `int`. It's value is undefined if declared inside `main()`, `0` if declared globally.

`ip` is a pointer to `int`. It's value is `null`

> (c)

`ip` is a pointer to int. It's value is undefined.

`ip2` is an `int`. It's value is undefined if declared inside `main()`, `0` if declared globally.

<a name="Section_2.4">Section 2.4</a>
---
### Exercise 2.26

> (a)

Illegal. `const` must be initialised when it is declared since it cannot be changed once created.

> (b)

Legal. `cnt` is an `int` who's value is `0`.

> (c)

Legal. `sz` is a `const` who's value is initialised to `cnt`'s value, `0`.

> (d)

Incrementing `cnt` is legal, incrementing `sz` is illegal since it is a `const` can cannot be changed.

<a name="Section_2.4.2">Section 2.4.2</a>
---
### Exercise 2.27

> (a)

The definition of `i` is legal, the definition of `r` is illegal since references must refer to an existing object.

> (b)

Legal so long as `i2` is of type `int`. `p2` is a constant pointer to `int`, meaning it will always point to the address of `i2`.

> (c)

Legal. `i` is a constant `int`, `r` is a constant reference to a temporary `int` object created by the compiler.

> (d)

Legal provided `i2` is of type `int`. `p3` is a constant pointer to a constant `int`

> (e)

Legal provided `i2` is of type `int`. `p1` is a pointer to an `int` constant, meaning the value of `p1` cannot be changed.

> (f)

Illegal. References are not objects so the `const` qualifier cannot be applied. Since references cant be changed once they are bound to an object, they are essentially `const` anyway.

> (g)

Legal. `i2` is a constant `int`, `r` reference to constant `int`.

### Exercise 2.28

> (a)

The value of `i` is undefined if declared within main, '0' otherwise. `cp` is illegal, a `const` pointer must be initialised.

> (b)

`p1` is an undefined pointer to `int`. `p2` is illegal, a `const` pointer must be initialised.

> (c)

Illegal. `ic` is a constant `int` so must be initialised, `r` is a reference to `const int`

> (d)

Illegal. `const` pointers must be initialised.

> (e)

`p` is an undefined pointer to a constant `int`

### Exercise 2.29

**Note:** *Since most of the answers to exercise 2.28 are illegal definitions, I will assume that this exercise is just referring to 'type' compatibility so I will assume that all variables from the previous exercise are legally defined for this exercise.*

> (a)

Legal, value of `ic` is copied to `i`.

> (b)

Illegal, `p3` points to a `const int`. If we were able to make this assignment it would be possible to manipulate a `const` object, which we wouldn't want.

> (c)

Illegal, similar to the question above. If assigning a `const int` object to a non `const int` pointer was legal, we'd be able to manipulate the `const` object.

> (d)

Illegal, `p3` is a constant pointer meaning the memory address it points to cannot be changed once defined.

> (e)

Illegal, same as above. `p2` is a constant pointer and cannot be reassigned.

> (f)

Illegal, `ic` is a `const int`, it's value cannot be changed once defined.

<a name="Section_2.4.3">Section 2.4.3</a>
---
### <a name="exercise_2_30">Exercise 2.30</a>

| Declaration                                      | Const type / Description         |
| :---:                                            | :---                             |
| `const int v2 = 0;`                              | v2 = Top-level `const`           |
| `int v1 = v2;`                                   | v1 = Non `const int`             |
| `int *p1 = &v1, &r1 = v1`                        | p1 = Non `const` pointer, r1 = low-level `const` |
| `const int *p2 = &v2, *Const p3 = &i, &r2 = v2;` | p2 = low-level `const`, p3 = both top-level and low-level `const`, r2 = low-level `const` |

**Note:** *references are, by default, low-level `const`*

##Exercise 2.31

| Statement  | Description               |
| :---:      | :---                      |
| `r1 = v2;` | Legal, `v2`'s top-level `const` is ignored |
| `p1 = p2;` | Illegal `p2` is low-level `const` `p1` is not |
| `p2 = p1;` | Legal, `p1`'s type is converted to `const int`. `p2` is low-level |
| `p1 = p3;` | Illegal, `p3`'s top-level `const` is ignored, base type is low-level | `const` `p1` is not |
| `p2 = p3;` | Legal, `p3`'s top-level `const` is ignored base types are both `const int` |

<a name="Section_2.4.4">Section 2.4.4</a>
---
### Exercise 2.32

This code is *not* legal, a pointer must be initialised to the address of an object, a literal `0`, `nullptr`, or another pointer (creates a copy). So to fix this code we could turn `null` into a pointer:
```cpp
int *null = 0, *p = null;
```
`p` is a copy of `null`, both of which are independent `null` pointers.
Another option, if `null` was required to remain as an `int`, would be to simply initialise `p` to a `nullptr`:
```cpp
int null = 0, *p = nullptr;
```
Lastly we can assign directly to zero:
```cpp
int null = 0, *p = 0;
```
Using `nullptr` is likely the best solution.

<a name="Section_2.5.2">Section 2.5.2</a>
---
### Exercise 2.33

| Definition | Type / Value  | Result |
| :---:      | :---          |  :---  |
| `a = 42;`  | `a` is an `int`, it's value is 42. | Legal. |
| `b = 42;`  | `b` is an `int`, it's value is 42. | Legal. |
| `c = 42;`  | `c` is an `int`, it's value is 42. | Legal. |
| `d = 42;`  | `d` is an `int*`, it holds the address of `i`. | Illegal, needs to be dereferenced to assign a value. |
| `e = 42;`  | `e` is a `const int*`, it holds the address of `ci`. | Illegal, pointed to type is `const`. |
| `g = 42;`  | `g` is a `const int&`, it refers to `ci`. | Illegal, referred to type is `const`. |

### [Exercise 2.34](exercise_34.cpp)

### [Exercise 2.35](exercise_35.cpp)

| Definition | Type / Value |
| :---:      | :---         |
| `auto j = i;` | `j` is an `int`, with the value of `i` **copied** into it. |
| `const auto &k = i;` | `k` is a reference to `const int`, it referrs to `i` who's value is 42. Note that the `const` keyword is redundant in this definition as references are by default `const` as noted in [exercise 2.30](#exercise_2_30). |
| ` auto *p = &i;` | `p` is a pointer to `const int`, it points to `i` who's value is 42. |
| `const auto j2 = i, &k2 = i;` | `j2` is a new `const int` with the value of i **copied** into it. `k2` is a reference to `const int`, it referrs to `i` who's value is 42. Again, the `const` qualifier for the reference definition is redundant. |

<a name="Section_2.5.3">Section 2.5.3</a>
---
### Exercise 2.36

| Definition | Type / Value| After Incrementing |
| :---:      | :---        | :---               |
| `decltype(a) c = a;` | `c` is an `int`, the value of `a` is **copied** into it | `c` is 4, `a` remains 3 |
| `decltype((b)) d = a;` | `d` is an `int&` to `a` | `d` is 4 therefore `a` is 4, `b` remains 4 |

### Exercise 2.37

| Definition | Type / Value|
| :---:      | :---        |
| `decltype(a) c = a;` | `c` is an `int`, the value of `a` (3)  is **copied** into it |
| `decltype(a = b) d = a;` | `d` is an `int&` to `a`, it's value is 3 |

### Exercise 2.38

`auto` deduced types will ignore top level `const` whereas `decltype` will not.
```cpp
const int i = 42;

auto ai = i;           // ai is an int
decltype(i) di = i;    // di is a const int
```

When `auto` is used with a reference type, the deduced type is that of the referred to object. `decltype` will instead produce a reference type.
```cpp
int i = 42;
int& r = i;

auto ai = r;           // ai is an int
decltype(r) ri = r;    // ri is a int&
```

If we want `decltype` to deduce the same type as `auto` in the previous example we could use an expression.
```cpp
decltype(r + 0) ri = r;
```

By using an expression `decltype` is now using the expressions return type. An `int` (r is a reference to `int`) plus an `int` (0 is an `int`) returns an `int`.

`auto` and `decltype` will deduce the same type when dealing with basic types with no modifiers.
```cpp
int i = 42;

auto ai = i;           // ai is an int
decltype(i) di = i;    // di is an int
```

One other thing to note about `decltype` is that if we surround a variable with parentheses it will be treated as an expression, the result of which is a reference type.
```cpp
int i = 42;

decltype((i)) di = i;    // di is an int&
```

<a name="Section_2.6.1">Section 2.6.1</a>
---
### Exercise 2.39

Compiler output
```
exercise_39.cpp:1:26: error: expected ‘;’ after struct definition
 struct Foo { /* empty */ } // Note: no semicolon
                          ^
```

### [Exercise 2.40](exercise_40.cpp)

<a name="Section_2.6.2">Section 2.6.2</a>
---
### Exercise 2.41

**Note:** Run all of these exercises with the [books.txt](../data/books.txt) data file to save having to type out the sale data each time.

[Exercise 2.41a](exercise_41a.cpp) (Rewrite of exercise [1.20](../Chapter_01/exercise_20.cpp) using my version of the `Sales_data` class)

Sample output:
```
$ ./Chapter_02/exercise_41a < ../data/books.txt
ISBN: 0-006-47988-X
Units sold: 1
Price (each): 12.95
Total revenue: 12.95

ISBN: 0-006-47988-X
Units sold: 1
Price (each): 12.95
Total revenue: 12.95

ISBN: 0-006-47988-X
Units sold: 1
Price (each): 12.95
Total revenue: 12.95

ISBN: 0-007-46582-3
Units sold: 4
Price (each): 22.45
Total revenue: 89.8

ISBN: 0-006-48612-6
Units sold: 3
Price (each): 19
Total revenue: 57

ISBN: 0-007-48384-8
Units sold: 7
Price (each): 32.5
Total revenue: 227.5

ISBN: 0-007-11955-0
Units sold: 2
Price (each): 10
Total revenue: 20

ISBN: 0-002-24739-9
Units sold: 1
Price (each): 50
Total revenue: 50

ISBN: 0-002-24739-9
Units sold: 1
Price (each): 50
Total revenue: 50
```

[Exercise 2.41b](exercise_41b.cpp) (Rewrite of exercise [1.21b](../Chapter_01/exercise_21b.cpp) using my version of the `Sales_data` class)

Sample output:
```
$ ./Chapter_02/exercise_41b < ../data/books.txt 
ISBN: 0-006-47988-X
Units sold: 2
Total revenue: 25.9
Average Price (each): 12.95
```

[Exercise 2.41c](exercise_41c.cpp) (Rewrite of exercise [1.22b](../Chapter_01/exercise_22b.cpp) using my version of the `Sales_data` class)

Sample output:
```
$ ./Chapter_02/exercise_41c < ../data/books.txt 
ISBN: 0-006-47988-X
Units sold: 3
Total revenue: 38.85
Average Price (each): 12.95
```

[Exercise 2.41d](exercise_41d.cpp) (Rewrite of exercise [1.23](../Chapter_01/exercise_23.cpp) using my version of the `Sales_data` class)

Exercise 2.41e (Exercise 1.24 using code from exercise 2.41d above)
```
$ ./Chapter_02/exercise_41d <../data/books.txt 
3 Transaction(s) for ISBN '0-006-47988-X'
1 Transaction(s) for ISBN '0-007-46582-3'
1 Transaction(s) for ISBN '0-006-48612-6'
1 Transaction(s) for ISBN '0-007-48384-8'
1 Transaction(s) for ISBN '0-007-11955-0'
```

[Exercise 2.41f](exercise_41f.cpp) (Rewrite of exercise [1.25](../Chapter_01/exercise_25.cpp) using my version of the `Sales_data` class)

Sample output:
```
$ ./Chapter_02/exercise_41f < ../data/books.txt 
0-006-47988-X 3 38.85 12.95
0-007-46582-3 4 89.8 22.45
0-006-48612-6 3 57 19
0-007-48384-8 7 227.5 32.5
0-007-11955-0 2 20 10
0-002-24739-9 1 50 50
```

<a name="Section_2.6.3">Section 2.6.3</a>
---
### Exercise 2.42

[Sales_data.hpp](../include/Sales_data.hpp) (Rewrite of my `Sales_data` class as a header file)

[Exercise 2.42a](exercise_42a.cpp) (Rewrite of exercise [1.20](../Chapter_01/exercise_20.cpp) using my version of the `Sales_data.hpp` header file)

[Exercise 2.42b](exercise_42b.cpp) (Rewrite of exercise [1.21b](../Chapter_01/exercise_21b.cpp) using my version of the `Sales_data.hpp` header file)

[Exercise 2.42c](exercise_42c.cpp) (Rewrite of exercise [1.22b](../Chapter_01/exercise_22b.cpp) using my version of the `Sales_data.hpp` header file)

[Exercise 2.42d](exercise_42d.cpp) (Rewrite of exercise [1.23](../Chapter_01/exercise_23.cpp) using my version of the `Sales_data.hpp` header file)

Exercise 2.42e (Exercise 1.24 using code from exercise 2.42d above)
```
$ ./Chapter_02/exercise_42d <../data/books.txt 
3 Transaction(s) for ISBN '0-006-47988-X'
1 Transaction(s) for ISBN '0-007-46582-3'
1 Transaction(s) for ISBN '0-006-48612-6'
1 Transaction(s) for ISBN '0-007-48384-8'
1 Transaction(s) for ISBN '0-007-11955-0'
```

[Exercise 2.42f](exercise_42f.cpp) (Rewrite of exercise [1.25](../Chapter_01/exercise_25.cpp) using my version of the `Sales_data.hpp` header file)

**Note:** Output for all exercises in 2.42 are the same as 2.41.

---
[☚ Chapter 01](../Chapter_01) Chapter 02 [Chapter 03 ☛](../Chapter_03)

[Home](https://github.com/adobrich/CppPrimer)
