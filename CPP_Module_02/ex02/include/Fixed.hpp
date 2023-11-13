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
      
      // The 6 comparison operators: >, <, >=, <=, == and !=

      bool operator<(const Fixed& compare) const;
      bool operator>(const Fixed& compare) const;
      bool operator<=(const Fixed& compare) const;
      bool operator>=(const Fixed& compare) const;
      bool operator==(const Fixed& compare) const;
      bool operator!=(const Fixed& compare) const;

      // The 4 arithmetic operators: +, -, *, and /
      Fixed operator+(const Fixed& arithm);
	  	Fixed operator-(const Fixed& arithm);
	  	Fixed operator*(const Fixed& arithm);
		  Fixed operator/(const Fixed& arithm);

      // The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
      Fixed&	operator++(void);
      Fixed	operator++(int);
      Fixed&	operator--(void);
      Fixed	operator--(int);


      static Fixed	&max( Fixed &a, Fixed &b);
      static Fixed	&min( Fixed &a, Fixed &b);
      
      static const Fixed &max( const Fixed &a, const Fixed &b);
      static const Fixed &min( const Fixed &a, const Fixed &b);
  private:
    int value;
    static const int fractionalBits = 8;
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif