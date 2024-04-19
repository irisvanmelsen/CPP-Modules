#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"
#include "string.h"

// TEMPLATES IN CPP:
// The simple idea is to pass the data type as a parameter so
// that we don’t need to write the same code for different data types.

template <typename T>
void swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
	
}

template <typename T>
T &min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif