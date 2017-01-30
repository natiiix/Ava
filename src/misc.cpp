#include <iostream>

#include "h/misc.hpp"

void writeLine(const char output[])
{
    std::cout << output << std::endl;
}

void pause()
{
    std::cout << "Press any key to continue...";
    std::cin.get();
}