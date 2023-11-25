
#include "WrongAnimal.hpp"
#include "animal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal's default constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string obj) {
	std::cout << "WrongAnimal's copy constructor has been called." << std::endl;
	this->type = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	this->type = obj.type;
	std::cout << "WrongAnimal's copy assignment operator called." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal's destructor called." << std::endl;
}

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << type << " says: WROOOOONG Animal Sound!" << std::endl;
}