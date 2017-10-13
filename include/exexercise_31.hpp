#ifndef EXERCISE_31_HPP
#define EXERCISE_31_HPP

// Forward declaration
class Y;

class X
{
public:
    X() = default;

private:
    Y* why = nullptr;
}; // end X class

class Y
{
public:
    Y() = default;

private:
    X ex = X();
}; // end Y class

#endif // EXERCISE_31_HPP

