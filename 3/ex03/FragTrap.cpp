#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hp = 100;
	this->mana = 100;
	this->att = 30;
	std::cout <<  "FragTrap Constructor Called\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor Called\n";
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other){
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " wants a high five!\n";
}