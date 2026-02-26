#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

bool ValidNum(std::string input)
{
	int decimalCount = 0;
	int start = 0;

	if (input[0] == '+' || input[0] == '-')
		start = 1;
	for (int i = start; i < (int)input.length(); i++)
	{
		if (isdigit(input[i]))
			continue;
		else if (input[i] == '.' && decimalCount == 0)
			decimalCount++;
		else
			return (false);
	}
	return (true);
}

int FindType(std::string input)
{
	if (input.length() == 1 && isdigit(input[0]))
		return (INT);
	if (input.length() == 0)
		return (ERROR);
	if (!input.compare("-inff") || !input.compare("inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (FLOAT);
	if (!input.compare("-inf") || !input.compare("inf") || !input.compare("+inf") || !input.compare("nan"))
		return (DOUBLE);
	if (input.length() == 1 && isprint(input[0]))
		return (CHAR);
	if (input[input.length() - 1] == 'f' || input[input.length() - 1] == 'F')
	{
		std::string num = input.substr(0, input.length() - 1);
		if (ValidNum(num))
			return (FLOAT);
		return (ERROR);
	}
	if (!ValidNum(input))
		return (ERROR);
	if (std::find(input.begin(), input.end(), '.') != input.end())
		return (DOUBLE);
	else
		return (INT);
}

void PrintValue(char c, int i, float f, double d)
{
	if (i >= 0 && i <= 127 && isprint(static_cast<unsigned char>(i)))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (isascii(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	if (d == (double)i)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	char c;
	int i;
	float f;
	double d;

	switch (FindType(input))
	{
		case CHAR:
		{
			c = input[0];
			PrintValue(c, c, c, c);
			return;
		}
		case INT:
		{
			char *end;
			errno = 0;
			long value = strtol(input.c_str(), &end, 10);
			if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: " << static_cast<float>(value) << "f\n";
				std::cout << "double: " << static_cast<double>(value) << "\n";
				return;
			}
			i = static_cast<int>(value);
			PrintValue(static_cast<char>(i), i, i, i);
			return;
		}
		case FLOAT:
		{
			char *end;
			errno = 0;
			f = strtof(input.c_str(), &end);
			if (std::isnan(f) || std::isinf(f))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<float>(f) << std::endl;
				return;
			}
			double f2 = strtod(input.c_str(), &end);
			if (f2 > std::numeric_limits<float>::max() || f2 < -std::numeric_limits<float>::max())
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: " << f2 << "\n";
				return;
			}
			PrintValue(static_cast<char>(f), static_cast<int>(f), f, f);
			return;
		}
		case DOUBLE:
		{
			char *end;
			errno = 0;
			d = strtod(input.c_str(), &end);
			if (std::isnan(d) || std::isinf(d))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
				return;
			}
			long double f2 = strtold(input.c_str(), &end);
			if (f2 > std::numeric_limits<double>::max() || f2 < -std::numeric_limits<double>::max())
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			PrintValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
			return;
		}
		case ERROR:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
}