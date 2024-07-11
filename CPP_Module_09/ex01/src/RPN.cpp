#include "RPN.hpp"

int RPN::do_calculation(std::string &arg, char calc) {
	int num1;
	int num2;

	if (arg.size() < 2) {
		std::cout << "Too little arguments to make calculation!" << std::endl;
		return (-1);
	}
	
	if (calc == '+') {

	}

}

bool RPN::is_cor_digit(char &c) {
	if (c >= 0 && c <= 9)
		return (true);
	return (false);
}

int RPN::calculate_arg(std::string &arg) {
	bool no_digit = false;
	std::stack<int> stack;
	for (int i = 0; arg[i] != '\0'; i++) {
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '/' || arg[i] == '*')
		{
			no_digit = true;
			do_calculation(arg, arg[i]);
		}
		if (no_digit == false && !is_cor_digit(arg[i]) || !isspace(arg[i]))
			std::cout << "Invalid Argument!" << std::endl;
		no_digit = false;
	}
}