#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Constructor Called\n";
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called\n";
}

Animal::Animal(Animal& other) {
	std::cout << "Animal Copy Constructor Called\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Assignment Operator Called\n";
	(void)other;
	return *this;
}

const std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "A sound of an unknown animal!\n";
}

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Constructor Called\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor Called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& other) {
	std::cout << "WrongAnimal Copy Constructor Called\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal Assignment Operator Called\n";	
	(void)other;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "A very wrong animal sound\n";
}

const std::string WrongAnimal::getType() const {
	return this->type;
}
