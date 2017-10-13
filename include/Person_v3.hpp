// Provide operations in your Person class to return the name and address.
// Should these functions be const? Explain your choice.

#ifndef PERSON_V3_HPP
#define PERSON_V3_HPP

#include <istream>
#include <string>

struct Person
{
    std::string name;
    std::string address;
    std::string get_name() const;
    std::string get_address() const;
    std::istream& read(std::istream& input, Person& person);
    std::ostream& print(std::ostream& output, const Person& person);
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
    input >> person.name >> person.address;
    return input;
}

std::ostream& print(std::ostream& output, const Person& person)
{
    output << person.name << " " << person.address;
    return output;
}

#endif // PERSON_V3_HPP
