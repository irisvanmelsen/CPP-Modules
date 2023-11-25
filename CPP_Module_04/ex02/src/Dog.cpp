#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog's Constructor has been called" << std::endl;
    this->brain = new Brain();
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog's Deconstructor has been called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& obj) {
    std::cout << "Dog's Copy Constructor has been called" << std::endl;
    this->type = obj.type;
    this->brain = new Brain(*(obj.brain));
    return;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog's Copy assignment has been called" << std::endl;

    if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }

    return (*this);
}

void    Dog::makeSound( void ) const
{
    std::cout << "Wooooooooooooff!" << std::endl;
}

std::string Dog::getType() const {
    return type;
}