#ifndef RPN_HPP
#define RPPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(std::string &str);
		RPN(RPN const &obj);
		RPN& operator=(RPN const &obj);

		int calculate_arg(std::string &arg);
		bool is_cor_digit(char &c);
};

#endif