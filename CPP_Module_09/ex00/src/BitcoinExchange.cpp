#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange's default deconstructor has been called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &obj) {
	std::cout << "BitcoinExchange's default copy constructor has been called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &in) {
	if (this != &in)
	{
		this->
	}
	std::cout << "BitcoinExchange's operator overload has been called" << std::endl;
	return ();
}

void BitcoinExchange::GoThroughData(std::string in) {

}