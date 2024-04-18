#include "Data.hpp"

Data::Data() : _value(5) {
	std::cout << "Data's default constructor has been called" << std::endl;
}

Data::Data(int _value) {
	std::cout << "Constructor Data(" << _value << ")" << std::endl;
}

int	Data::getValue() const {
	return (_value);
}

void	Data::setValue(int value) {
	this->_value = value;
}