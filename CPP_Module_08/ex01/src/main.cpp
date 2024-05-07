#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

std::cout << "add to list instead of calling addNumber" << std::endl;
Span sp2 = Span(5);
std::vector<int> list = {1, 2, 3, 4, 5};
sp2.fillSpan(list);
sp2.displayArray();

std::cout << "test with 10 000 numbers" << std::endl;
Span sp3 = Span(10000);
std::vector<int> thous_list(10000);
for (int i = 0; i < 10000; i++)
	thous_list[i] = i + 1;
sp3.fillSpan(thous_list);
sp3.displayArray();
}