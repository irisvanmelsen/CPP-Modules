
#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called!" << std::endl;
    value = 0;
}


// the value is incremented first, modification occurs before the value is used
Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

// The modification occurs after the value is used.
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	++(*this);
	return (old);
}

// the value is decremented first, modification occurs before the value is used
Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

// The modification occurs after the value is used.
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	--(*this);
	return (old);
}

// The 6 comparison operators: >, <, >=, <=, == and !=
bool	Fixed::operator>(const Fixed& compare) const {
	return (value > compare.value);
}

bool	Fixed::operator<(const Fixed& compare) const {
	return (value < compare.value);
}

bool	Fixed::operator>=(const Fixed& compare) const {
	return (value >= compare.value);
}

bool	Fixed::operator<=(const Fixed& compare) const {
	return (value <= compare.value);
}

bool	Fixed::operator==(const Fixed& compare) const {
	return (value == compare.value);
}

bool	Fixed::operator!=(const Fixed& compare) const {
	return (value != compare.value);
}

// The 4 arithmetic operators: +, -, *, and /
Fixed	Fixed::operator*(const Fixed& arithm) {
	Fixed	tmp;

    tmp = this->toFloat() * arithm.toFloat();
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& arithm) {
	Fixed	tmp;

    tmp = this->toFloat() / arithm.toFloat();
	return (tmp);
}

Fixed Fixed::operator+(const Fixed& arithm) {
    Fixed tmp;
    
    tmp = this->toFloat() + arithm.toFloat();
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& arithm) {
    Fixed tmp;

    tmp = this->toFloat() - arithm.toFloat();
    return (tmp);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

// it converts the int by 8 which is the fixed-point representation
Fixed::Fixed(const int i)
{
    // std::cout << "Int constructor called" << std::endl;
    value = i << this->fractionalBits;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// takes a float and scales it to fixed-point value and rounds result using roundf
Fixed::Fixed(const float number)
{
    // std::cout << "Float constructor called" << std::endl;
    this->value = roundf(number * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    value = copy.value;
    return *this;
}

Fixed::~Fixed()
{
//      std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)(value) / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}