#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: You must provide at least one number to sort." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        // Add numbers from the command line arguments
        for (int i = 1; i < argc; ++i) {
            sorter.AddNumberToBoth(argv[i]);
        }

        sorter.SortData();
    } catch (const PmergeMe::InvalidNumbersException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const PmergeMe::DoubleNumbersException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    return 0;
}