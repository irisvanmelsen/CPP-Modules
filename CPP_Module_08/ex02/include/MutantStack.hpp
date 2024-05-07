#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <deque>
#include <list>

// a container is a data structure used to store, organize, and manage objects in memory
// containers are implemented as class templates in the Standard Template Library (STL)

// std::stack is a LIFO (last in, first out) data structure and is not inherently iterable
// because it doesn't provide direct access to its elements, except the top one

// std::deque (double-ended queue) is an indexed sequence container that allows fast
// insertion and deletion at both its beginning and its end
// has iteration function begin(), end() etc

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &obj);

		MutantStack &operator=(const MutantStack &obj);

		// creating your own name "iterator" within your class to refer to the iterator type of the underlying container that std::stack uses
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif