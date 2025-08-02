#include "Cat.hpp"


Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat Constructor Called\n";
	this->brain = new Brain();
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat Destructor Called\n";
}

Cat::Cat(Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor Called\n";
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat&other) {
	std::cout << "Cat Assignment Operator Called\n";
	this->brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow!\n";
}

WrongCat::WrongCat() {
	std::cout << "WrongCat Constructor Called\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor Called\n";
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal(other) {
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	(void)other;
	return *this;
}
void WrongCat::makeSound() const {
	std::cout << "Mewing!\n";
}

Brain* Cat::getBrain() const {
	return this->brain;
}