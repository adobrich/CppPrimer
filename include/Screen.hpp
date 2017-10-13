#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>

class Screen
{
public:
    typedef std::string::size_type position;
    Screen() = default;
    Screen(position height, position width, char value)
        : m_height(height)
        , m_width(width)
        , m_contents(height * width, value)
    {}

    char get() const
    {
        return m_contents[m_cursor];
    }

    char get(position height, position width) const;
    
private:
    position m_cursor = 0;
    position m_height = 0;
    position m_width = 0;
    std::string m_contents;
}; // Screen class

inline
char Screen::get(position row, position column) const
{
    return m_contents[(row * m_width) + column];
}

#endif // SCREEN_HPP

