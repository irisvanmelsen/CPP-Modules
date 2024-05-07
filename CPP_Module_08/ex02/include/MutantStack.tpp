#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << "MutantStack's Default Constructor has been called!" << std::endl;
}

// c representing the container
// this member c holds the underlying container that std::stack adapts to provide its functionality.
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj) {
    std::cout << "MutantStack's operator has been called!" << std::endl;
    if (this != &obj) {
        this->c = obj.c;
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack's Destructor has been called!" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &obj) {
	std::cout << "MutantStack's Copy Constructor has been called!" << std::endl;
    *this = obj;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

#endif