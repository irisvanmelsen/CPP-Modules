
#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(std::string);
        ~Dog();
        
        Dog &operator=(const Dog &obj);
        void makeSound() const;
};

#endif