#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong Format" << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	ScalarConverter::convert(input);
}

/*
	+inf
	-inf
	nan
	+inff
	-inff
	nanf


*/