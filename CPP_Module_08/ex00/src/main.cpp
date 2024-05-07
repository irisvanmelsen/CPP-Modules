#include "easyfind.hpp"

int main (void) {
	// vector test
	std::vector<int> vect = {1, 2, 3, 4, 5};
	try {
		int index = easyfind(vect, 3);
		std::cout << "index has been found in vector at index: " << index << std::endl;
	} catch (std::exception& e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
	// list test
	std::list<int> lst = {10, 20, 30, 40, 50};
    try {
        int index = easyfind(lst, 20);
        std::cout << "Found 20 in list at index: " << index << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	// test with value not in container
    int index = easyfind(vect, 99);
	if (index != -1)
        std::cout << "Found 99 in vector at index: " << index << std::endl;
    else 
        std::cout << index << " was not found in vector!" << std::endl;
}