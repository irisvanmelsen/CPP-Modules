#ifndef RPN_HPP
#define RPPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
	public:
		int calculate_arg(const std::string &arg);
		bool is_cor_digit(char &c);
		int do_calculation(std::stack<int>& stack, char calc);
};

#endif