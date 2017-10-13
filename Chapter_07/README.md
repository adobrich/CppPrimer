# Chapter Seven Answers

<a name="Section_7.1.1">Section 7.1.1</a>
---

### [Exercise 7.1](exercise_01.cpp)

<a name="Section_7.1.2">Section 7.1.2</a>
---

### [Exercise 7.2](../include/Sales_data_v2.hpp)

### [Exercise 7.3](Chapter_07/exercise_03.cpp)

### [Exercise 7.4](../include/Person.hpp)

### [Exercise 7.5](../include/Person_v2.hpp)

If these member functions are not `const` the following would be illegal

```cpp
const Person andy;
std::cout << andy.get_address() << std::endl;
```

Since `andy` is a `const Person` he can only call member functions with the same constness.

If we define these member functions to be `const` both a `const Person` and a `Person` (non `const`) can utilise them. Having `const` member functions effectively increases their flexibility.

<a name="Section_7.1.3">Section 7.1.3</a>
---

### [Exercise 7.6](../include/Sales_data_v3.hpp)

### [Exercise 7.7](exercise_07.cpp)

### Exercise 7.8

In the `read` member function we need write access to the `Sales_data` object to 'read in' the data.  `print` only requires reading of the data already stored in the `Sales_data` object, so it should be 'read only' or `const`.

### [Exercise 7.9](../include/Person_v3.hpp)

### Exercise 7.10

We work this one from the inside out. First the inner `read` reads data into `data1` it then returns a reference to an `istream` object (as per our header file from the previous exercise) which is then used as the input to feed data to `data2`.

This statement will `be`true only if there is enough data to satisfy both `data1` and `data2`, it will be `false` otherwise.

<a name="Section_7.1.4">Section 7.1.4</a>
---

### Exercise 7.11

[Sales_data](../include/Sales_data_v4.hpp)

[Test of each constructor](exercise_11.cpp)

### [Exercise 7.12](../include/Sales_data_v5.hpp)

### [Exercise 7.13](exercise_13.cpp)

### [Exercise 7.14](../include/Sales_data_v6.hpp)

### [Exercise 7.15](../include/Person_v4.hpp)

<a name="Section_7.2">Section 7.2</a>
---

### Exercise 7.16

There is no limit on how many times an access specifier can appear within a `struct` or `class`.  Each definition following a specifier has the specified 'visibility' until either the next specifier or end of class is reached.

### Exercise 7.17

The only difference between `struct` and `class` is default 'visibility'. A `struct` defaults to `public` where as a `class` defaults to `private`.

### Exercise 7.18

Encapsulation 'hides' the implementation.  Only the class it's self is able to access the encapsulated members. This helps show intent and guard against incorrect use of the class since only the `public` members are available to the user of the class.

### Exercise 7.19

The constructors, `get_name()` & `get_address()` member functions would be `public` to allow creation of the object and read only access to it's data.

The member variables `name` and `address` should be `private` to prevent direct access to the classes data.  Access should only be granted via the interface (public methods).

<a name="Section_7.2.1">Section 7.2.1</a>
---

### Exercise 7.20

Friends are useful when you have functions related to a class, but which are not part of the class interface. Defining them as 'friends' allows these functions access to private members of the class.
I don't see any notable cons to using `friend`s other than the *possible* need to declare the function twice (once inside the class, once outside the class).

### [Exercise 7.21](../include/Sales_data_v7.hpp)

Output of [exercise 7.13](exercise_13.cpp) using updated `Sales_data` class:
```
0-006-47988-X 3 38.85
0-007-46582-3 4 89.8
0-006-48612-6 3 57
0-007-48384-8 7 227.5
0-007-11955-0 2 20
0-002-24739-9 1 50
```

### [Exercise 7.22](../include/Person_v5.hpp)

<a name="Section_7.3.1">Section 7.3.1</a>
---

### [Exercise 7.23](../include/Screen.hpp)

### [Exercise 7.24](../include/Screen_v2.hpp)

### Exercise 7.25

Since the data members are stored within the object using `string`s the synthesised assignment and copy operators are fine. It is only when we store data members externally / in dynamic memory that the synthesised operators will not be adequate.

### [Exercise 7.26](../include/Sales_data_v8.hpp)

<a name="Section_7.3.2">Section 7.3.2</a>
---

### [Exercise 7.27](../include/Screen_v3.hpp)

[Exercise 7.27 test file](exercise_27.cpp)

Sample output:
```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
```

### Exercise 7.28

If we aren't dealing with a *reference* to a `Screen` object, we would then be using a *copy* instead. Changes to this temporary copy will not change the original object.
In the case of the example code from the exercise above, here's what happens:

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
```
Here we construct `myScreen`, a 5 x 5 screen filled with the `char` 'X'. On the second line we chain 3 methods, first we move the cursor to the 4th row, then we replace the 'X' at that location with a '#', then we print the output.  Now, since we are not using references, all these actions take place on the temporary copy of the `myScreen` object. No change is made to the original `myScreen` object.

Output of the above code:
```
XXXXXXXXXXXXXXXXXXXX#XXXX
```

```cpp
myScreen.display(cout);
cout << "\n";
```
Here we call display on the original object thus yielding the original unchanged screen:

```
XXXXXXXXXXXXXXXXXXXXXXXXX
```

### [Exercise 7.29](../include/Screen_v4.hpp)

Output of [code](exercise_29.cpp) from exercise 7.27 using updated `Screen` class:
```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

### Exercise 7.30

*Pros*:
Shows intent. Guards against accidentally hiding member variables. For example, defining a variable in function scope with the same name as a member variable.

*Cons*:
More to type. Allows you to have two variables with the same name which can make things confusing.

### [Exercise 7.31](../include/exercise_31.hpp)

### [Exercise 7.32](../include/Screen_v5.hpp)

### Exercise 7.32

The `pos` type is not defined in this scope. It is defined inside the `Screen` class.  This snippet will not compile.

To access the `pos` type from outside the class we need to prefix it with `Screen::`

```cpp
Screen::pos Screen::size() const
{
    return height * width;
}
```

---
[☚ Chapter 06](../Chapter_06) Chapter 07 [Chapter 08 ☛](../Chapter_08)

[Home](https://github.com/adobrich/CppPrimer)
