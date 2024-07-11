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
    std::regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
    return std::regex_match(date, pattern);
}

bool BitcoinExchange::isValidValue(const std::string &value) {
    try {
        double val = std::stod(value);
        return (val >= 0 && val <= 1000);
    } catch (...) {
        return false;
    }
}

std::string BitcoinExchange::getClosestDate(const std::string &date) {
    auto it = data.lower_bound(date);
    if (it == data.end() || (it != data.begin() && it->first != date)) {
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

    if (!isValidValue(value)) {
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
    std::getline(file, line);
    if (line != "date | value") {
        throw std::runtime_error("Incorrect data, file should start with 'date | value'");
    }

    while (std::getline(file, line)) {
        std::size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos) {
            throw std::runtime_error("Incorrect format: " + line);
        }

        std::string date = line.substr(0, delimiterPos - 1);
        std::string valueStr = line.substr(delimiterPos + 2);

        if (!isValidDate(date)) {
            throw std::runtime_error("Invalid date format: " + date);
        }
        if (!isValidValue(valueStr)) {
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

            std::string closestDate = getClosestDate(date);
            double exchangeRate = data[closestDate];
            double result = value * exchangeRate;

            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
