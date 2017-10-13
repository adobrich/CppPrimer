// Provide operations in your Person class to return the name and address.
// Should these functions be const? Explain your choice.

#ifndef PERSON_V4_HPP
#define PERSON_V4_HPP

#include <istream>
#include <string>

// Forward declaration
struct Person;
std::istream& read(std::istream& input, Person& person);
std::ostream& print(std::ostream& output, const Person& person);

struct Person
{
    Person() = default;

    Person(const std::string name, const std::string address)
        : name(name)
        , address(address)
    { }

    Person(std::istream& input)
    {
        read(input, *this);
    }

    std::string name;
    std::string address;
    std::string get_name() const;
    std::string get_address() const;
}; // Person Class

std::string Person::get_name() const
{
    return this->name;
}

std::string Person::get_address() const
{
    return this->address;
}

std::istream& read(std::istream& input, Person& person)
{
    // Grab data one line at a time (to allow for spaces)
    std::getline(input, person.name);
    std::getline(input, person.address);
    return input;
}

std::ostream& print(std::ostream& output, const Person& person)
{
    output << person.name << " " << person.address;
    return output;
}

#endif // PERSON_V4_HPP
