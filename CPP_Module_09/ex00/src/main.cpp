#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {
	if (argc == 2) {
		try {
		BitcoinExchange btc;

		btc.go_through_Data(argv[1]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			return (EXIT_FAILURE);
		}
	}
	else {
		std::cout << "The program needs ./btc and an input file to work!" << std::endl;
	}
}
