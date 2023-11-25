
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &obj);
        virtual ~Animal();

        Animal& operator=(const Animal &obj);

        virtual void makeSound(void) const;
        std::string getType() const;
};

#endif