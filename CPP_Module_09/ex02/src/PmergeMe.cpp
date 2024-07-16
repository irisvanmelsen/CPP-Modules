#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe's Default Constructor has been called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    std::cout << "PmergeMe's Copy Constructor has been called" << std::endl;
    *this = obj;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe's Destructor has been called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    std::cout << "PmergeMe's Operator Overload has been called" << std::endl;
	this->_deque = obj._deque;
	this->_vector = obj._vector;
    return *this;
}

void PmergeMe::SortVector() {
	
}

template <typename T>
void PmergeMe::PrintAnyArray(T array)
{
    int count = 0;
    for (auto it = array.begin(); it != array.end(); it++)
    {
        if (counter == 5)
        {
            std::cout << "[...]" << std::endl;
            break;
        }
        std::cout << *it << " ";
        count++;
    }
    std::cout << std::endl;
}

void	PmergeMe::SortData() {
	std::cout << "Before: " << PrintAnyArray(this->_vector) << std::endl;

	this->SortVector();
	this->SortDeque();

	std::cout << "After: " << PrintAnyArray(this->_deque) << std::endl;
}