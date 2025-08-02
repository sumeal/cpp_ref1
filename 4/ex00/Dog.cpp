#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog Constructor Called\n";
}

Dog::~Dog() {
	std::cout << "Dog Destructor Called\n";
}

Dog::Dog(Dog& other) : Animal(other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	(void)other;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Bark Bark!\n";
}