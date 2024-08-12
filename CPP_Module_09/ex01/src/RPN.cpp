#include "RPN.hpp"

int RPN::operation(std::stack<std::string>& stak, const std::string& token, const std::string& num_2, const std::string& num_1) {
    int n1, n2;
    try {
        n1 = std::stoi(num_2);
        n2 = std::stoi(num_1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << ": one of the arguments is not valid" << std::endl;
        return 1;
    }

    int result = 0;
    if (token == "+") {
        result = n1 + n2;
    } else if (token == "-") {
        result = n1 - n2;
    } else if (token == "*") {
        result = n1 * n2;
    } else if (token == "/") {
        if (n2 == 0) {
            std::cout << "Error: Division by zero" << std::endl;
            return 1;
        }
        result = n1 / n2;
    } else {
        std::cout << "Error: Invalid operator!" << std::endl;
        return 1;
    }

    std::cout << "Operation " << n1 << " " << token << " " << n2 << " = " << result << std::endl;
    stak.push(std::to_string(result));  // Push the result back onto the stack as a string
    return 0;
}

bool RPN::is_cor_digit(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int RPN::calculate(const std::string& str) {
    std::stack<std::string> stak;
    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "/" || token == "*") {
            if (stak.size() < 2) {
                std::cout << "Error: Stack size is too small for an operation" << std::endl;
                return 1;
            }
            std::string num_1 = stak.top();
            stak.pop();
            std::string num_2 = stak.top();
            stak.pop();
            if (operation(stak, token, num_2, num_1)) {  // Notice the order of num_2 and num_1
                return 1;
            }
        } else {
            stak.push(token);
        }
    }

    if (stak.size() != 1) {
        std::cout << "Error: Invalid RPN expression! Stack size is not 1" << std::endl;
        return 1;
    }

    std::cout << "Final Result: " << stak.top() << std::endl;
    return 0;
}

