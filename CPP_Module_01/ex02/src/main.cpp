
#include <iostream>

// Pointers are declared using an asterisk *, and they store the memory address of a variable.
// References are declared using an ampersand &, and they are an alias for an existing variable.

// To access the value pointed to by a pointer, you need to use the dereference operator *.
// References are used like the original variable, without the need for a dereference operator.

int main (void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory Address" << std::endl;
    std::cout << "\n";
    std::cout << "of the string variable: " << &string << std::endl;
    std::cout << "held by stringPTR: " << &stringPTR << std::endl;
    std::cout << "held by stringREF: " << &stringREF << std::endl;
    std::cout << "\n";

    std::cout << "The value" << std::endl;
    std::cout << "\n";
    std::cout << "of the string variable: " << string << std::endl;
    std::cout << "pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "pointed to by stringREF: " << stringREF << std::endl;

}