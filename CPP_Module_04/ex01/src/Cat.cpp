#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat's Constructor has been called" << std::endl;
    this->brain = new Brain();
    this->type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat's Deconstructor has been called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat& obj) {
    std::cout << "Cat's Copy Constructor has been called" << std::endl;
    this->type = obj.type;
    this->brain = new Brain(*(obj.brain));
    return;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat's Copy assignment has been called" << std::endl;

    if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }

    return (*this);
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meeeeeeeeooow!" << std::endl;
}

std::string Cat::getType() const {
    return type;
}