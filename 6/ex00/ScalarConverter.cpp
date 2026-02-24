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
	if (input.length() == 0)
		return (ERROR);
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (FLOAT);
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (DOUBLE);
	if (input.length() == 1 && isalpha(input[0]))
		return (CHAR);
	if (input[input.length() - 1] == 'f')
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
		std::cout << "char: " << c << std::endl;
	else if (isascii(i))
		std::cout << "char: non displayable" << std::endl;
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
			PrintValue(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
			return;
		}
		case INT:
		{
			char *end;
			errno = 0;
			long value = strtol(input.c_str(), &end, 10);
			if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: " << static_cast<float>(value) << "f\n";
				std::cout << "double: " << static_cast<double>(value) << "\n";
				return;
			}
			i = static_cast<int>(value);
			PrintValue(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
			return;
		}
		case FLOAT:
		{
			char *end;
			errno = 0;
			double f2 = strtof(input.c_str(), &end);
			if (errno == ERANGE || f2 > FLT_MAX || f2 < -FLT_MAX)
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: " << f2 << "\n";
				return;
			}
			f = strtof(input.c_str(), &end);
			if (std::isnan(f) || std::isinf(f))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<float>(f) << std::endl;
				return;
			}
			PrintValue(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
			return;
		}
		case DOUBLE:
		{
			char *end;
			errno = 0;
			d = strtod(input.c_str(), &end);
			if (errno == ERANGE)
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible\n";
				std::cout << "double: impossible" << "\n";
				return;
			}
			if (std::isnan(d) || std::isinf(d))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
				return;
			}
			PrintValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
			return;
		}
	}
}