#include "iter.hpp"


void just_print(const int &num)
{
	std::cout << num << " ";
}

void just_increment(int &num)
{
	num++;
}

void test_normal()
{
	int test[] = {1, 2, 3, 4, 5};
	const int length = 5;

	std::cout << "+++++++++  test_normal  +++++++++++" << std::endl;
	::iter(test, length, just_print);
	::iter(test, length, just_increment);
	std::cout << std::endl;
	std::cout << "After" << std::endl;
	::iter(test, length, just_print);
	std::cout << std::endl;

}

void test_const()
{
	const int test[] = {6, 7, 8, 9, 10};
	const int length = 5;

	std::cout << "+++++++++  test_const  +++++++++++" << std::endl;
	::iter(test, length, just_print);
	//::iter(test, length, just_increment);
	std::cout << std::endl;

}

void print_char(const char c)
{
	std::cout << c << " ";
}

void uppercase_char(char &c)
{
	c = std::toupper(c);
}

void test_char_normal ()
{
	char letters[] = {'a','b','c','d','e'};
    const int length = 5;

	std::cout << "+++++++++  test_char_normal  +++++++++++" << std::endl;
    ::iter(letters, length, print_char);
    std::cout << std::endl;
    ::iter(letters, length, uppercase_char);
	std::cout << "After" << std::endl;
    ::iter(letters, length, print_char);
    std::cout << std::endl;
}

void test_char_const ()
{
	const char letters[] = {'a','b','c','d','e'};
    const int length = 5;

	std::cout << "+++++++++  test_char_const  +++++++++++" << std::endl;
    ::iter(letters, length, print_char);
    std::cout << std::endl;
    // ::iter(letters, length, uppercase_char);
    // ::iter(letters, length, print_char);
    // std::cout << std::endl;
}

int main()
{
	test_normal();
	test_const();
	test_char_normal();
	test_char_const();
	return (0);
}