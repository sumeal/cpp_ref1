#include "Animal.hpp"

Animal::~Animal() {
	std::cout << "Animal Destructor Called\n";
}

const std::string& Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "A sound of an unknown animal!\n";
}
