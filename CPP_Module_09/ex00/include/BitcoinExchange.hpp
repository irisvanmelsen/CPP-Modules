#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <regex>



class BitcoinExchange {
	private:
		std::map<std::string, double>	data;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void isValidDate(const std::string &data);
		bool CheckValue(const std::string &value);

		std::string getClosestDate(const std::string &date);
		void checkInputFormat(const std::string &line);
		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);

};

#endif