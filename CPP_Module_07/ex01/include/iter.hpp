#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


// template instantiation:
// the act of creating a new definition of a function, class, or member
// of a class from a template declaration and one or more template arguments

template <typename T>
void print_ch(T &argument){
    std::cout << "current argument: " << argument << std::endl; 
}

template <typename T, typename F>
void iter(T *array, size_t length, F function) {
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif