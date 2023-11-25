
#include "cat.hpp"
#include "animal.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat's default constructor has been called." << std::endl;
}

Cat::Cat(std::string obj) {
	std::cout << "Cat's copy constructor has been called." << std::endl;
	this->type = obj;
}

Cat &Cat::operator=(const Cat &obj) {
	this->type = obj.type;
	std::cout << "Cat's copy assignment operator called." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat's destructor called." << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << type << " says: Meeeeeeeeeoow!" << std::endl;
}