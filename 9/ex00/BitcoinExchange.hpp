#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <map>
 #include <iterator>
 #include <sstream>
 #include <cctype>
 #include <cstdlib>
 #include <iomanip>

 class NotPositiveException : public std::exception
 {
	public :
		const char* what() const throw()
		{
			return ("Error: not a positive number.");
		}
 };

 class TooLargeException : public std::exception
 {
	public :
		const char* what() const throw()
		{
			return ("Error: too large a number.");
		}
 };
 
 class BadInputException : public std::exception
 {
	public:
		const char* what() const throw()
		{
			return ("Error: bad input");
		}
 };

 enum Month
 {
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OCTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12,
 };
 
 class BitcoinExchange
 {
	private:
		std::map<std::string, float> _data;
		std::string _curYear;
		float _curValue;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void readCSV();
		void setData(std::string data, float rate);
		std::map<std::string, float> getData() const;
		void readInput(char *filename);
		void parseInput(std::string line);
		bool isLeapYear(int year);
		void checkDate();
		void checkLimit();
		void run();

 };

#endif