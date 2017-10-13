#ifndef SCREEN_V3_HPP
#define SCREEN_V3_HPP

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

    Screen& set(char value);
    Screen& set(position row, position column, char value);

    Screen& display(std::ostream& output)
    {
        do_display(output);
        return *this;
    }

    const Screen& display(std::ostream& output) const
    {
        do_display(output);
        return *this;
    }

private:
    void do_display(std::ostream& output) const
    {
        output << m_contents;
    };
    position m_cursor = 0;
    position m_height = 0;
    position m_width = 0;
    std::string m_contents;
}; // Screen class

#endif // SCREEN_V3_HPP

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

inline
Screen& Screen::set(char value)
{
    m_contents[m_cursor] = value;
    return *this;
}

inline
Screen& Screen::set(position row, position column, char value)
{
    m_contents[row * m_width + column] = value;
    return *this;
}
