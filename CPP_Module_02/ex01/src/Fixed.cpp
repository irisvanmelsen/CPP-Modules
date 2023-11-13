
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called!" << std::endl;
    value = 0;
}


// it converts the int by 8 which is the fixed-point representation
Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    value = i << this->fractionalBits;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// takes a float and scales it to fixed-point value and rounds result using roundf
Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(number * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = copy.value;
    return *this;
}

Fixed::~Fixed()
{
     std::cout << "Destructor called" << std::endl;
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