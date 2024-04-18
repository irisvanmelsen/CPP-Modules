#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "Not Enough Arguments!" << std::endl;
	for (int i = 1; i < argc; i++)
		ScalarConverter::convert(std::string(argv[i]));
}