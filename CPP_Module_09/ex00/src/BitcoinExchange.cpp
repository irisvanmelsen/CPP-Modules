#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange's Default Constructor has been called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
    std::cout << "BitcoinExchange's Copy Constructor has been called" << std::endl;
    *this = obj;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange's Destructor has been called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
    std::cout << "BitcoinExchange's Operator Overload has been called" << std::endl;
    if (this != &obj) {
        this->data = obj.data;
    }
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    std::regex pattern(R"(^\d{4}-\d{2}-\d{2}$)"); // 4 digits, 2 digits, 2 digits
    return std::regex_match(date, pattern);
}

bool BitcoinExchange::CheckValue(const std::string &value) {
    try {
        std::stod(value);
        return (true);
    } catch (...) { // catch (...) can handle any type of exception
        return (false);
    }
}

std::string BitcoinExchange::getClosestDate(const std::string &date) {
    auto it = data.lower_bound(date); // returns iterator to first element less than date
    if (it == data.end() || (it != data.begin() && it->first != date)) { // it == end means no data greater than it, other option means lowerbound found data greater
        --it;
    }
    return it->first;
}

void BitcoinExchange::checkInputFormat(const std::string &line) {
    if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
        throw std::runtime_error("Incorrect format. Expected 'YYYY-MM-DD | value'");
    }

    std::string date = line.substr(0, 10);
    std::string value = line.substr(13);

    if (!isValidDate(date)) {
        throw std::runtime_error("Invalid date format: " + date);
    }

    if (!CheckValue(value)) {
        throw std::runtime_error("Invalid value format: " + value);
    }
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    if (filename != "data.csv") {
        throw std::runtime_error("Invalid database file. Expected 'data.csv'.");
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file 'data.csv'.");
    }

    std::string line;
    std::getline(file, line); // skip first line

    while (std::getline(file, line)) {
        std::size_t delimiterPos = line.find(',');
        if (delimiterPos == std::string::npos) {
            throw std::runtime_error("Incorrect format: " + line);
        }

        std::string date = line.substr(0, delimiterPos);
        std::string valueStr = line.substr(delimiterPos + 1);

        if (!isValidDate(date)) {
            throw std::runtime_error("Invalid date format: " + date);
        }
        if (!CheckValue(valueStr)) {
            throw std::runtime_error("Invalid value format: " + valueStr);
        }

        double value = std::stod(valueStr);
        data[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::getline(file, line);
    if (line != "date | value") {
        throw std::runtime_error("Incorrect format. Expected 'date | value'");
    }

    while (std::getline(file, line)) {
        try {
            checkInputFormat(line);

            std::string date = line.substr(0, 10);
            std::string valueStr = line.substr(13);
            double value = std::stod(valueStr);

            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            std::string closestDate = getClosestDate(date);
            double exchangeRate = data[closestDate];
            double result = value * exchangeRate;

            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}