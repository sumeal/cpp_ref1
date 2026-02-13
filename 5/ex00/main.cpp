#include "Bureaucrat.hpp"

void normalTest()
{
	try
	{
		Bureaucrat man1("Ali", 60);
		std::cout << man1 << std::endl;
		man1.safe_Increment(man1);        
		std::cout << man1 << std::endl;
		man1.safe_Decrement(man1);        
		std::cout << man1 << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat man2("Muthu", 1);
		std::cout << man2 << std::endl;
		man2.safe_Increment(man2);
		std::cout << man2 << std::endl;
		man2.safe_Decrement(man2);
		std::cout << man2 << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat man3("Ah Hock", 150);
		std::cout << man3 << std::endl;
		man3.safe_Decrement(man3);        
		man3.safe_Increment(man3);        
		std::cout << man3 << std::endl;
		man3.safe_Decrement(man3);        
		std::cout << man3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void createTest()
{
	try
	{
		Bureaucrat("Ahmad", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat("Muzzammil", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void copyTest()
{
	Bureaucrat a("Test", 42);
	Bureaucrat b(a);
	std::cout << b << std::endl;
}

int main()
{
	normalTest();
	std::cout << std::endl;
	createTest();
	std::cout << std::endl;
	copyTest();
	std::cout << std::endl;
	return(0);
}