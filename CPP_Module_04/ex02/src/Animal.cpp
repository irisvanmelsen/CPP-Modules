#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal's Constructor has been called" << std::endl;
    this->type = "Animal";
}

Animal::~Animal() {
    std::cout << "Animal's Deconstructor has been called" << std::endl;
}

Animal::Animal(const Animal& obj) {
    std::cout << "Animal's Copy Constructor has been called" << std::endl;
    this->type = obj.type;
    return;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal's Copy assignment has been called" << std::endl;

    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

void    Animal::makeSound( void ) const
{
    std::cout << "Meeeeeeeeooow!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}