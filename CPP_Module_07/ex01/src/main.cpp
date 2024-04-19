#include "iter.hpp"

// dividing the total size of the array by the size of one element gives the number of elements in the array.


int main(void) {
	std::string array[] = {"one", "two", "three"};
	int length = sizeof(array) / sizeof(array[0]);
	iter(array, length, print_ch<std::string &>);
	std::cout << std::endl;

	int ints[] = {1, 2, 3, 4};
	int ints_length = sizeof(ints) / sizeof(ints[0]);
	iter(ints, ints_length, print_ch<int>);
	std::cout << std::endl;
}	