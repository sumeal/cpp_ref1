#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	Animal a;

	std::cout << "\n--- Creating Animals ---\n" << std::endl;

	const int N = 4;
	Animal* animals[N];

	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- Testing Deep Copy ---\n" << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Chase mice");

	Cat copiedCat = originalCat; // invokes deep copy constructor
	copiedCat.getBrain()->setIdea(0, "Nap on laptop");

	std::cout << "Original Cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Cat idea[0]:   " << copiedCat.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Deleting Animals ---\n" << std::endl;

	for (int i = 0; i < N; ++i)
		delete animals[i];

	std::cout << "\n--- Done ---\n" << std::endl;

	return 0;
}
