
#include "Fixed.hpp"

// Integers are whole numbers without any decimal points.
// They can be either positive or negative, or even zero. For example, 1, -5, and 0 are integers.

// Floating-point numbers, on the other hand, can represent numbers with decimal points
// or in exponential form. They include a fractional part, which allows
// for a more precise representation of numbers. Examples: 3.14, -0.5.

// Unlike floating-point numbers that use a binary representation
// fixed-point numbers use a fixed number of bits for the integer and fractional parts.

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
}