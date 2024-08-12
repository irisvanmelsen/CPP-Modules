#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
	public:
		bool is_cor_digit(char c);
		int operation(std::stack<std::string>& stak, const std::string& token, const std::string& num_2, const std::string& num_1);
		int calculate(const std::string& str);
};

#endif