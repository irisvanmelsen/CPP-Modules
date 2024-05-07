#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop(); // removes 17
std::cout << mstack.size() << std::endl; // is 1 now instead of 2
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0); // the contents of the stack at this point, from top to bottom, are: 0, 737, 5, 3, 5.
MutantStack<int>::iterator it = mstack.begin(); // is 5 (bottom element)
MutantStack<int>::iterator ite = mstack.end(); // points past 0 element
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl; // prints each element from top to bottom
++it;
}
std::stack<int> s(mstack);

std::cout << std::endl;

std::list<int>	list;
	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

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