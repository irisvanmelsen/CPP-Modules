
#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &obj);
        ~Animal();

        Animal &operator=(const Animal &obj);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif