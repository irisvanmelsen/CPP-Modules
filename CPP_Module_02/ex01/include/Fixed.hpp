#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

// FixedPointNumber& operator=(const FixedPointNumber &copy):
// declares a copy assignment operator for the FixedPointNumber class.
// It takes a constant reference to another FixedPointNumber object,
// copies its value to the current object, and returns a reference to the current object.

// When we say "the copy assignment operator is overloaded," it means that a class
// has provided a custom implementation for the assignment operator (operator=).

// std::ostream is a C++ standard library class that represents the output stream. 

class Fixed
{
   public:
      Fixed();
      Fixed(const int i);
      Fixed(const float number);
      Fixed(const Fixed &copy);
      Fixed& operator = (const Fixed& copy);
      ~Fixed();

      float toFloat(void) const;
      int toInt(void) const;

  private:
    int value;
    static const int fractionalBits = 8;
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif