
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// FixedPointNumber& operator=(const FixedPointNumber &copy):
// declares a copy assignment operator for the FixedPointNumber class.
// It takes a constant reference to another FixedPointNumber object,
// copies its value to the current object, and returns a reference to the current object.

// When we say "the copy assignment operator is overloaded," it means that a class
// has provided a custom implementation for the assignment operator (operator=).

class Fixed
{
  private:
    int value; /* stores fixed-point number value */
    static const int franctionalBits = 8; 
   public:
    Fixed();
    Fixed(const Fixed &copy); /* copy constructor */
    Fixed &operator = (const Fixed &copy); /* copy assignment operator overload */
    ~Fixed(); /* destructor */

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif