#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong format !" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.readCSV();
	btc.readInput(av[1]);
}