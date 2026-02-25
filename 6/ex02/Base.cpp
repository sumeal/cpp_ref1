#include "Base.hpp"

Base::~Base()
{

}

Base *generate(void)
{
	int random_num = rand() % 3;

	if (random_num == 0)
		return (new A());
	else if (random_num == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *base)
{
	if (dynamic_cast<A*>(base) != NULL)
		std::cout << "Class A pointer" << std::endl;
	else if (dynamic_cast<B*>(base) != NULL)
		std::cout << "Class B pointer" << std::endl;
	else if (dynamic_cast<C*>(base) != NULL)
		std::cout << "Class C pointer" << std::endl;
	else
		std::cout << "Unknown class pointer" << std::endl;
}

void identify(Base &base)
{
	try
	{
		(void)dynamic_cast<A&>(base);
		std::cout << "Class A reference" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(base);
		std::cout << "Class B reference" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(base);
		std::cout << "Class C reference" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
}