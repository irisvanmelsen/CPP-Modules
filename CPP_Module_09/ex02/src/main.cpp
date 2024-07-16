#include "PmergeMe.hpp"

int main (int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: should contain both ./PmergeMe and arguments" << std::endl;
		return (-1);
	}
	try {
		PmergeMe mergeMe;
		mergeMe.SortData(argv[1]);
		
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}