#include "Zombie.hpp"

void Zombie::setName (std::string name) {
	this->name = name;
}

void Zombie::announce() {
	std::cout << this->name
			  << ": BraiiiiiiinnnzzzZ..."
			  <<std::endl;
}

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << this->name
			  << " is destroyed"
			  <<std::endl;
}