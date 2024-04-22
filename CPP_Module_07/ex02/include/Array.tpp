#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// you MUST use the operator new[] to allocate memory

// construction with no parameter: creates an empty array
template <typename T>
Array<T>::Array() : _n(1){
    std::cout << "Array's Default Custructor has been called!" << std::endl;
    array = new T[_n];
}

// construction with an unsigned int n as a parameter: creates an array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n) : _n(n) {
	std::cout << "Array's Constructor has been called!" << std::endl;
	_array = new T[_n];
}

// modifying either the original array or its copy after copying mustn’t affect the other array
template <typename T>
Array<T>::Array(const Array<T> &obj) {
    std::cout << "Array's Copy Constructor has been called!" << std::endl;
	this->_n = obj.size();
	this->_array = new T[_n];
	for (int i = 0; i < _n; i++) {
		this->_array[i] = obj._array[i];
	}
	return this->_array;
}

// destructor
template <typename T>
Array<T>::~Array() {
    std::cout << "Array's Destructor has been called!" << std::endl;
    if (this->_array)
        delete[] array;
}

//  a member function size() that returns the number of elements in the array
template <typename T>
int Array<T>::size() const{
    return _n;
}

// when accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
template <typename T>
const char * Array<T>::outOfBoundException::what() const throw() {
	return ("Index is out of bound!")
}

// elements can be accessed through the subscript operator: [ ]
template <typename T>
T& Array<T>::operator[](int i) {
	if (i < 0 || i >= _n) {
		throw (outOfBoundException());
		return (array[0])
	}
	return (array[i]);
}

// modifying either the original array or its copy after copying mustn’t affect the other array
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &obj) {
	std::cout << "Array's Assignment Operator has been called!" << std::endl;
	if (this != &obj) {
		this->_n = obj.size();
		_array = new T[_n];
		for (int i = 0; i < _n; i++)
			_array[i] = obj._array[i];
	}
	return *this;
}

#endif