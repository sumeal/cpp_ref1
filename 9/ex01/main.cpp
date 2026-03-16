#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please provide Reverse Polish Notation" << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	if (input.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return (1);
	}
	RPN test;
	test.runRPN(input);
}