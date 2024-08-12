#include "RPN.hpp"

int RPN::do_calculation(std::stack<int>& stack, char calc) {
	static int flag = 0;
	if (stack.size() < 2) {
		std::cout << stack.size() << std::endl;
		std::cout << "Too little arguments to make calculation!" << std::endl;
		return (-1);
	}
	if (stack.size() > 2 && flag != 1) {

		std::stack<int> temp_stack;
		while (!stack.empty()) {
			temp_stack.push(stack.top());
			stack.pop();
		}
		stack = temp_stack;
		flag = 1;
	}
	int num2 = stack.top(); // top element of stack is stored in num2;
	stack.pop();
	int num1 = stack.top(); // next top element is stored in num1;
	stack.pop();
	int result;

	switch (calc) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				std::cout << "Error: Division by zero!" << std::endl;
				return -1;
			}
			result = num2 / num1;
			break;
		default:
			std::cout << "Error: Invalid operator!" << std::endl;
			return -1;
	}
	stack.push(result);
    return 0;
}

bool RPN::is_cor_digit(char &c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int RPN::calculate_arg(const std::string &arg) {
    std::stack<int> stack;
    std::istringstream iss(arg);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*')) {
            if (do_calculation(stack, token[0]) == -1) {
                return -1;
            }
        } else if (token.size() == 1 && is_cor_digit(token[0])) {
            stack.push(token[0] - '0');
        } else {
            std::cout << "Error: Invalid argument!" << std::endl;
            return -1;
        }
    }
    if (stack.size() != 1) {
        std::cout << "Error: Invalid RPN expression!" << std::endl;
        return -1;
    }

    std::cout << stack.top() << std::endl;
    return 0;
}