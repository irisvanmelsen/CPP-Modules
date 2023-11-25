
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &obj);
        ~Brain();

        Brain& operator=(const Brain &obj);
};

#endif