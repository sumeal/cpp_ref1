#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	Animal* animals[10];

	for(int i = 0; i < 5; i++)
	{
		animals[i] = new Dog();
	}
	for(int i = 5; i < 10; i++)
	{
		animals[i] = new Cat();
	}	
	for(int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	Cat old;
	old.getBrain()->setIdea(0, "Jump");

	Cat notOld = old;

    std::cout << "Before change:" << std::endl;
    std::cout << "Original idea: " << old.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea:     " << notOld.getBrain()->getIdea(0) << std::endl;

    notOld.getBrain()->setIdea(0, "Eat");

    std::cout << "\nAfter change in copy:" << std::endl;
    std::cout << "Original idea: " << old.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea:     " << notOld.getBrain()->getIdea(0) << std::endl;

	return 0;
}