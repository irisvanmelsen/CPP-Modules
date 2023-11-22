
#include "animal.hpp"

Animal::Animal() {
    std::cout << "Animal's default constructor has been called" << std::endl;
}

Animal::Animal(const Animal &obj) {
    *this = obj;
    std::cout << "Animal's constructor has been called" << std::endl;
}

Animal &Animal::operator(const Animal &obj) {
    if (this != &obj)
        this->type = obj.type;
    std::cout << "Animal's copy operator has been called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal's Destructor has been called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void    Animal::makeSound() const {
    std::cout << "Animal Sound ??? " << std::endl;
}