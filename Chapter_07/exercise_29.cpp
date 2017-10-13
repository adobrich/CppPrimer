// Revise your Screen class so that move, set and display functions return
// Screen and check your prediction from the previous exercise.
#include <iostream>

#include "../include/Screen_v4.hpp"

int main()
{
    Screen my_screen(5, 5, 'X');
    my_screen.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;
    my_screen.display(std::cout);
    std::cout << std::endl;

    return 0;
}

