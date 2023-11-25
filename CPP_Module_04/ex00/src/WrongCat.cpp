
#include "WrongCat.hpp"
#include "animal.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat's default constructor has been called." << std::endl;
}

WrongCat::WrongCat(std::string obj) {
	std::cout << "WrongCat's copy constructor has been called." << std::endl;
	this->type = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
	this->type = obj.type;
	std::cout << "WrongCat's copy assignment operator called." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat's destructor called." << std::endl;
}

void WrongCat::makeSound( void ) const {
	std::cout << type << " says: WROOONG Meeeeeow!" << std::endl;
}