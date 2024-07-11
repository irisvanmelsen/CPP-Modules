#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {
	if (argc == 2) {
<<<<<<< HEAD
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
=======
		BitcoinExchange program;

		program.GoThroughData(argv[1]);
	}
	else
		std::cout << "Needs 2 arguments: ./btc and a database file in csv format!" << std::endl;
}
>>>>>>> 42fa59ea46b4358f2e186843b7bc2e236329a847
