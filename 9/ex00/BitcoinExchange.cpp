#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib> // For atof
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readCSV()
{
    std::ifstream csv("data.csv");
    std::string line;
    
    if (!csv.is_open()) {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }

    std::getline(csv, line); // Skip header
    while (std::getline(csv, line))
	{
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos)
		{
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            float rate = static_cast<float>(std::atof(rateStr.c_str()));
            _data[date] = rate;
        }
    }
    csv.close();
}

void BitcoinExchange::parseInput(std::string line)
{
    if (line.length() < 14 || line.find(" | ") == std::string::npos)
        throw BadInputException();

    _curYear = line.substr(0, 10);
    
    // Validate date format YYYY-MM-DD
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
		{
            if (_curYear[i] != '-')
				throw BadInputException();
        }
		else
		{
            if (!std::isdigit(_curYear[i]))
				throw BadInputException();
        }
    }

    std::string valueStr = line.substr(13);
    _curValue = static_cast<float>(std::atof(valueStr.c_str()));
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::checkDate()
{
    int year = std::atoi(_curYear.substr(0, 4).c_str());
    int month = std::atoi(_curYear.substr(5, 2).c_str());
    int day = std::atoi(_curYear.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || year < 2008) // BTC started 2009
        throw BadInputException();

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year))
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        throw BadInputException();
}

void BitcoinExchange::checkLimit()
{
    if (_curValue < 0)
        throw NotPositiveException();
    if (_curValue > 1000)
        throw TooLargeException();
}

void BitcoinExchange::run()
{
    std::map<std::string, float>::iterator it = _data.lower_bound(_curYear);

    if (it == _data.end() || it->first != _curYear)
	{
        if (it == _data.begin())
            throw BadInputException();
        --it;
    }
    std::cout << _curYear << " => " << _curValue << " = ";
    std::cout << std::fixed << std::setprecision(2) << (_curValue * it->second);
    std::cout.unsetf(std::ios::fixed | std::ios::scientific);
    
    std::cout << std::endl;
}
void BitcoinExchange::readInput(char *filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::getline(file, line); // Skip header "date | value"
    while (std::getline(file, line))
	{
        try
		{
            parseInput(line);
            checkDate();
            checkLimit();
            run();
        }
		catch (const std::exception &e)
		{
            // Adjust this to match the exact error output format required
            if (std::string(e.what()) == "Error: bad input")
                std::cout << e.what() << " => " << line << std::endl;
            else
                std::cout << e.what() << std::endl;
        }
    }
    file.close();
}