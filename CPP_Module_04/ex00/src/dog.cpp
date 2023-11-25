
#include "dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog's default constructor has been called." << std::endl;
}

Dog::Dog(std::string obj) {
	std::cout << "Dog's copy constructor has been called." << std::endl;
	this->type = obj;
}

Dog &Dog::operator=(const Dog &obj) {
	this->type = obj.type;
	std::cout << "Dog's copy assignment operator called." << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog's destructor called." << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << type << " says: Woooooof!" << std::endl;
}