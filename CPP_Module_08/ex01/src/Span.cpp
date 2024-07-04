#include "Span.hpp"

Span::Span() {
	std::cout << "Span's default constructor has been called" << std::endl;
}

// N is an unsigned int variable and will be the only parameter passed to the constructor
Span::Span(unsigned int _n) : N(_n) {
	std::cout << "Span's constructor has been called" << std::endl;
}

Span::~Span() {
	std::cout << "Span's destructor has been called" << std::endl;
}

Span::Span(const Span &obj) {
	this->N = obj.N;
	this->_array = obj._array;
}

Span &Span::operator=(const Span &obj) {
	std::cout << "Span's copy operator has been called" << std::endl;
	if (this != &obj) {
		this->N = obj.N;
		this->_array = obj._array;
	}
	return *this;
}

// vector::push_back: adds a new element at the end of the vector, after its current last element
// std::out_of_range: reports errors that are consequence of attempt to access elements out of defined range

void Span::addNumber(int index) {
	if (_array.size() < N) {
		_array.push_back(index);
		std::cout << "number " << index << " added to vector!" << std::endl;
	}
	else {
		throw std::out_of_range("can't add more numbers to vector, max has been reached!");
	}
}

// std::logic_error: it reports errors that are a consequence of faulty logic within the program
// such as violating logical preconditions or class invariants and may be preventable
int Span::shortestSpan() {
	if (_array.size() < 2)
		throw std::logic_error("there are not enough numbers to find span!");
	std::sort(_array.begin(), _array.end()); // sorts elements in range
	int minSpan = std::numeric_limits<int>::max(); // max possible value of int
	for (size_t i = 1; i < _array.size(); i++)
            minSpan = std::min(minSpan, _array[i] - _array[i - 1]);
	return (minSpan);
}

int Span::longestSpan() {
	if (_array.size() < 2)
		throw std::logic_error("there are not enough numbers to find span!");
	int min = *std::min_element(_array.begin(), _array.end());
    int max = *std::max_element(_array.begin(), _array.end());;
    return (max - min);
}

void Span::fillSpan(std::vector<int> list) {
	if (list.size() + _array.size() > N)
		throw std::logic_error("there are too many arguements, can't add more!");
	else
		_array.insert(_array.end(), list.cbegin(), list.cend()); 

}

void Span::displayArray() {
	for (int i = 0; i < (int)_array.size(); i++)
		std::cout << _array[i] << " - ";
	std::cout << std::endl;
}