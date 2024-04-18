#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

typedef enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FAILED,
} t_type;

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		static void	convert(const std::string &str);
};

#endif