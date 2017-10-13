// Provide operations in your Person class to return the name and address.
// Should these functions be const? Explain your choice.

#ifndef PERSON_V2_HPP
#define PERSON_V2_HPP

#include <string>

struct Person
{
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
#endif // PERSON_V2_HPP
