#include "easyfind.hpp"

void tryFind(std::vector<int> container, int toFind)
{
	try
	{
		easyfind(container, toFind);
		std::cout << "Found " << toFind << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> test;

	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}
	for (int i = 0; i < 6; i++)
	{
		tryFind(test, i);
	}
}