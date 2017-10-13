#ifndef SCREEN_V2_HPP
#define SCREEN_V2_HPP

#include <string>

class Screen
{
public:
    typedef std::string::size_type position;
    Screen() = default;
    Screen(position height, position width)
        : m_height(height)
        , m_width(width)
        , m_contents(height * width, ' ')
    {}
    Screen(position height, position width, char value)
        : m_height(height)
        , m_width(width)
        , m_contents(height * width, value)
    {}

    char get() const
    {
        return m_contents[m_cursor];
    }

    position len() const
    {
        return m_contents.length();
    }

    char get(position height, position width) const;
    
    Screen& move(position row, position column);

private:
    position m_cursor = 0;
    position m_height = 0;
    position m_width = 0;
    std::string m_contents;
}; // Screen class

#endif // SCREEN_V2_HPP

inline
Screen& Screen::move(position row, position column)
{
    m_cursor = (row * m_width) + column;
    return *this;
}

inline
char Screen::get(position row, position column) const
{
    return m_contents[(row * m_width) + column];
}
