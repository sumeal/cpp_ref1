#include "easyfind.hpp"


template <typename T>
void tryFind(const T& container, int toFind)
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

void testVector()
{
	std::cout << "----- VECTOR TEST -----" << std::endl;

	std::vector<int> vec;

	for (int i = 0; i < 5; i++)
		vec.push_back(i);

	for (int i = 0; i < 6; i++)
		tryFind(vec, i);

	std::cout << std::endl;
}

void testList()
{
	std::cout << "----- LIST TEST -----" << std::endl;

	std::list<int> lst;

	for (int i = 5; i < 10; i++)
		lst.push_back(i);

	for (int i = 4; i < 11; i++)
		tryFind(lst, i);

	std::cout << std::endl;
}

void testDeque()
{
	std::cout << "----- DEQUE TEST -----" << std::endl;

	std::deque<int> deq;

	for (int i = 10; i < 15; i++)
		deq.push_back(i);

	for (int i = 9; i < 16; i++)
		tryFind(deq, i);

	std::cout << std::endl;
}

int main()
{
	testVector();
	testList();
	testDeque();
	return 0;
}