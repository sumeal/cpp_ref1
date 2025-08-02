#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* k = new WrongCat();
	k->makeSound();
	std::cout << std::endl;
	
	delete i;
	delete j;
	delete k;
	delete meta;
	return 0;
}