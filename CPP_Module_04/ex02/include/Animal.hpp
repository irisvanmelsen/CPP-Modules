
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
        Animal();
        Animal(const Animal &obj);
    public:
        virtual ~Animal();
        Animal& operator=(const Animal &obj);

        virtual void makeSound(void) const;
        std::string getType() const;
};

#endif