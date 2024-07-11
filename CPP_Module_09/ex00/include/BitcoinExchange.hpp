#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>



class BitcoinExchange {
	private:
		std::map<std::string, double>	data;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void go_through_Data(std::string const &in);
		void go_through_Date(std::string const &line);
		bool digits_in_Date(const std::string &str);


};