#include "whatever.hpp"

void test_int()
{
	std::cout << "/////// test_int ////////" << std::endl;
	int test1 = 5;
	int test2 = 7;
	std::cout << "Before : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 <<std::endl;
	::swap(test1, test2);
	std::cout << "After : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 <<std::endl << std::endl;
	
}

void test_string()
{
	std::cout << "/////// test_string ////////" << std::endl;
	std::string test1 = "Hello";
	std::string test2 = "World";
	std::cout << "Before : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 <<std::endl;
	::swap(test1, test2);
	std::cout << "After : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 <<std::endl << std::endl;
	
}

void test_min()
{
	std::cout << "/////// test_min ////////" << std::endl;
	int test1 = 5;
	int test2 = 7;
	std::string test3 = "Hello1";
	std::string test4 = "Hello2";
	std::cout << "Before : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 << std::endl;
	std::cout << "Before : " << std::endl << "test3 = " << test3 << std::endl << "test4 = " << test4 <<std::endl << std::endl;
	std::cout << "min for int is: " << ::min(test1, test2) << std::endl << "min for string is: " << ::min(test3, test4) << std::endl << std::endl;
}

void test_max()
{
	std::cout << "/////// test_max ////////" << std::endl;
	int test1 = 5;
	int test2 = 7;
	std::string test3 = "Hello1";
	std::string test4 = "Hello2";
	std::cout << "Before : " << std::endl << "test1 = " << test1 << std::endl << "test2 = " << test2 << std::endl;
	std::cout << "Before : " << std::endl << "test3 = " << test3 << std::endl << "test4 = " << test4 <<std::endl << std::endl;
	std::cout << "max for int is: " << ::max(test1, test2) << std::endl << "max for string is: " << ::max(test3, test4) << std::endl << std::endl;
}

int main()
{
	test_int();
	test_string();
	test_min();
	test_max();
	return (0);
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }