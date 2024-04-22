#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "string.h"
#include <iostream>

template <typename T>
class Array {
	private:
		T* _array;
		int _n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &obj);

		T& operator[](int i);
		Array<T>& operator=(const Array<T> &obj);

		~Array();
		class outOfBoundException : public std::exception();
		public:
			virtual const char * what() const throw();

		int size() const;
};

#include "Array.tpp"

#endif