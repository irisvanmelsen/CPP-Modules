#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

// std::find = used to search for a specific element with a range defined by two iterators

// values.begin() and values.end() = return iterators to beginning and end of container

// search = value you are searching for

// std::distance = this function computes the number of elements between two iterators
// here, it is used to calculate the distance between the beginning of the container
// (values.begin()) and the iterator it where the element was found.

template <typename T>
int *easyfind(T &container, int target) {
	typename T::iterator it = std::find(values.begin(), values.end(), search);
	if (it != values.end()) {	
        std::cout << "Value found at index: " << std::distance(values.begin(), it) << std::endl;
        return std::distance(values.begin(), it);
	} else {
        std::cout << "Value not found!" << std::endl;
        return -1;
    }
}

#endif