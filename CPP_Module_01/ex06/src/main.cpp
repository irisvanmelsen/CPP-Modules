
#include "Harl.hpp"

// he switch statement is a control flow statement used for making decisions based on the value
// of a single expression or variable. 
// It provides a way to jump to different sections of code based on the value of the expression.

int main(int argc, char **argv)
{
    Harl    harl;

    if (argc != 2)
    {
        std::cout << "Invalid Amount of Arguments!" << std::endl;
        return (1);
    }

    int     choice = harl.level_choice(argv[1]);
    switch(choice)
    {
        case 0:
            std::cout << "DEBUG:" << std::endl;
            harl.complain("debug");
            break;
        case 1:
            std::cout << "INFO:" << std::endl;
            harl.complain("info");
            break;
        case 2:
            std::cout << "WARNING:" << std::endl;
            harl.complain("warning");
            break;
        case 3:
            std::cout << "ERROR:" << std::endl;
            harl.complain("error");
            break;
        default:
           std::cout << "This argument does not exist!" << std::endl;
    }
}