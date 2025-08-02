#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog Constructor Called\n";
	this->brain = new Brain();
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog Destructor Called\n";
}

Dog::Dog(Dog& other) : Animal(other) {
	std::cout << "Dog Copy Constructor Called\n";
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Assignment Operator Called\n";
	this->brain = new Brain(*other.brain);
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Bark Bark!\n";
}