#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {
	if (argc == 2) {
		BitcoinExchange program;

		program.GoThroughData(argv[1]);
	}
	else
		std::cout << "Needs 2 arguments: ./btc and a database file in csv format!" << std::endl;
}