#include "Cat.hpp"


Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat Constructor Called\n";
}

Cat::~Cat() {
	std::cout << "Cat Destructor Called\n";
}

Cat::Cat(Cat& other) : Animal(other) {
	*this = other;
}

Cat& Cat::operator=(const Cat&other) {
	(void)other;
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