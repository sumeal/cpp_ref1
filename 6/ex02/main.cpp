#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base* test = generate();
	identify(test);
	identify(*test);
	delete (test);
	return (0);
	
}