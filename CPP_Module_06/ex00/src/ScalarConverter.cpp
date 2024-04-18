#include "ScalarConverter.hpp"

static void char_output(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void int_output(int i)
{
    if (!isprint((unsigned char)i))
	    std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void float_output(float fl, const std::string &str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << fl << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(fl) << std::endl;
		return ;
	}
    if (!isprint(fl))
	    std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(fl) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(fl) << std::endl;
    std::cout << "float: " << fl << std::endl;
    std::cout << "double: " << static_cast<double>(fl) << std::endl;
}

static void double_output(double doubl, const std::string &str)
{
	if (str == "nan" || str == "-inf" || str == "+inf")
	    std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(doubl) << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return;
    if ((doubl > 2147483647 && doubl < -2147483648) && !isprint(doubl))
	   std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(doubl) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(doubl) << std::endl;
    std::cout << "float: " << static_cast<float>(doubl) << std::endl;
    std::cout << "double: " << doubl << std::endl;
}

static void failed_output(void)
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

static bool	check_if_char(const std::string &str) {
	if (str.size() != 1) // can only be one char
		return (false);
	if (isdigit(str[0])) // if digit
		return (false);
	return (true);
}

static bool check_if_int(const std::string &str) {
	int str_length = str.size() - 1;
	for (int i = 0; i < str_length; i++)
	{
		if (!isdigit(str[i]) && str[0] != '-')
			return (false);
	}
	try {
		std::stoi(str); // string to int
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid Argument " << e.what() << std::endl;
		return (false);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Out of Range " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static bool	check_if_float(const std::string &str) {
	if (str.empty() || str.size() == 1)
		return (false);
	try {
		std::stof(str); // string to float
			return (true);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid Argument " << e.what() << std::endl;
		return (false);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Out of Range " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static bool check_if_double(const std::string &str) {
	if (str.empty() || str.size() == 1)
		return (false);
	double dbl;
	try {
		dbl = std::stod(str); // string to double
			return (true);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid Argument " << e.what() << std::endl;
		return (false);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Out of Range " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static t_type	find_type(const std::string &str) {
	if ((str == "nan" || str == "-inf" || str == "+inf"))
		return (DOUBLE);
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (FLOAT);
	if (check_if_char(str))
        return (CHAR);
    if (check_if_int(str))
        return (INT);
    if (check_if_float(str) && str[str.size()-1] == 'f')
        return (FLOAT);
    if (check_if_double(str))
        return (DOUBLE);
    return (FAILED);
    
}

void ScalarConverter::convert(const std::string &str){
    switch (find_type(str))
    {
        case CHAR:
            char_output(str[0]);
            break;
        case INT:
            int_output(stoi(str));
            break;
        case FLOAT:
            float_output(stof(str), str);
            break;
        case DOUBLE:
            double_output(stod(str), str);
            break;
        case FAILED:
            failed_output();
            break;
    }
    std::cout << std::endl;
}