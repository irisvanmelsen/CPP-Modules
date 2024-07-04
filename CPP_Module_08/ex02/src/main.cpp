#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;

mstack.push(5);
mstack.push(17);

std::cout << "stack consists of 5 and 17" << std::endl;
std::cout << "top: " << std::endl;
std::cout << mstack.top() << std::endl;
std::cout << std::endl;

std::cout << "pop 17, it is now removed! " << std::endl;
mstack.pop(); // removes 17
std::cout << "size of the stack is now: " << std::endl;
std::cout << mstack.size() << std::endl; // is 1 now instead of 2
std::cout << std::endl;

mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);

std::cout << "the content of stack is now (bottom to top): 5, 3, 5, 737, 0" << std::endl;
MutantStack<int>::iterator it = mstack.begin(); // is 5 (bottom element)
MutantStack<int>::iterator ite = mstack.end(); // points past 0 element
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl; // prints each element from bottom to top
++it;
}
std::stack<int> s(mstack);

std::cout << std::endl;

	std::cout << "doing the same with a list!" << std::endl;
std::list<int>	list;
	std::cout << "stack consists of 5 and 17" << std::endl;
	list.push_back(5);
	list.push_back(17);

	std::cout << "list.back returns last element of the list: " << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "pop_back removes last element of the list(17) " << std::endl;
	list.pop_back();
	std::cout << "list size is now:  " << std::endl;
	std::cout << list.size() << std::endl;
	std::cout << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "the content of stack is now (bottom to top): 5, 3, 5, 737, 0" << std::endl;
	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	
	++it2;
	--it2;
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(list);

}