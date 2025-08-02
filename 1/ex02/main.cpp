#include <iostream>

int main() {
	std::string hello = "HI THIS IS BRAIN";
	std::string *stringPTR = &hello;
	std::string &stringREF = hello;

	std::cout << &hello << std::endl
			  << &stringPTR << std::endl
			  << &stringREF << std::endl;
	
	std::cout << hello << std::endl
			  << *stringPTR << std::endl
			  << stringREF << std::endl;

	return 0;
}