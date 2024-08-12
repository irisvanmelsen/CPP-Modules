#include "RPN.hpp"

int main (int argc, char **argv) {
	if (argc == 2) {
		RPN rpn;
		rpn.calculate_arg(argv[1]);
	}
	else
		std::cout << "Can only run with two arguments: ./RPN and polish notation" << std::endl;
}