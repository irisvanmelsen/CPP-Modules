#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>

class Span {
	private:
		unsigned int N;
		std::vector<int> _array;
	public:
	Span();
	Span(const Span &obj);
	Span(unsigned int _n);
	Span &operator=(const Span &obj);
	~Span();


	void addNumber(int numb);
	int	shortestSpan();
	int	longestSpan();
	void fillSpan(std::vector<int> list);
	void displayArray();
};

#endif