#include <iostream>

class BitcoinExchange {
	private:

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &obj);
		BitcoinExchange& operator=(BitcoinExchange &in);
		~BitcoinExchange();

		void GoThroughData(std::string in);
};