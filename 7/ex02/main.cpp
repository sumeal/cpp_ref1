#include "Array.tpp"

/*
	Need to ask why example main has <Array.hpp>
*/

void test_create_empty()
{
	std::cout << "-------test_create_empty-------" << std::endl;
	Array<int> test1;
	std::cout << "test1 size: " << test1.size() << std::endl;
	std::cout << std::endl;
}

void test_create_with_value()
{
	std::cout << "-------test_create_with_value-------" << std::endl;
	Array<int> test2(5);
	std::cout << "test2 size: " << test2.size() << std::endl;
	test2[0] = 1;
	test2[1] = 2;
	test2[2] = 3;
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test2[" << i << "]: " << test2[i] << std::endl;
	}
	std::cout << std::endl;
}

void test_out_of_bound()
{
	std::cout << "-------test_out_of_bound-------" << std::endl;
	Array<int> test2(5);
	try
	{
		std::cout << "test2[5]: " << test2[5] <<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_copy_assignment()
{
	std::cout << "-------test_copy_assignment-------" << std::endl;
	Array<int> test2(5);
	std::cout << "test2 size: " << test2.size() << std::endl;
	test2[0] = 1;
	test2[1] = 2;
	test2[2] = 3;

	Array<int> test_cpy = test2;
	std::cout << "test_cpy size: " << test_cpy.size() << std::endl;
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test_cpy[" << i << "]: " << test2[i] << std::endl;
	}
	std::cout << "change value for test_cpy: " << std::endl;
	test_cpy[0] = 4;
	test_cpy[1] = 5;
	test_cpy[2] = 6;
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test_cpy[" << i << "]: " << test_cpy[i] << std::endl;
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test2[" << i << "]: " << test2[i] << std::endl;
	}
	std::cout << std::endl;
}

void test_copy_constructor()
{
	std::cout << "-------test_copy_constructor-------" << std::endl;
	Array<int> test2(5);
	std::cout << "test2 size: " << test2.size() << std::endl;
	test2[0] = 1;
	test2[1] = 2;
	test2[2] = 3;
	Array<int> test_cpy2(test2);
	std::cout << "test_cpy2 size: " << test_cpy2.size() << std::endl;
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test_cpy2[" << i << "]: " << test2[i] << std::endl;
	}
	std::cout << "change value for test_cpy2: " << std::endl;
	test_cpy2[0] = 4;
	test_cpy2[1] = 5;
	test_cpy2[2] = 6;
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test_cpy2[" << i << "]: " << test_cpy2[i] << std::endl;
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "test2[" << i << "]: " << test2[i] << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	test_create_empty();
	test_create_with_value();
	test_out_of_bound();
	test_copy_assignment();
	test_copy_constructor();
	return (0);
}