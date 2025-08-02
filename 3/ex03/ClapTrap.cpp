#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap (std::string name) {
	this->hp = 100;
	this->mana = 50;
	this->att = 20;
	this->name = name;
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called\n";
	(void)other;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
	
	if (this->hp == 0) {
		std::cout << this->name << " is knocked out x(\n";
	}
	else if (this->mana == 0) {
		std::cout << "No energy!\n";
	}
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->att << " points of damage!\n";
		this->mana--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (amount >= this->hp) {
		std::cout << "ClapTrap " << this->name << " received " << amount << " damage and has been knocked out x(\n";
		this->hp = 0;
	}
	else {
		this->hp -= amount;
		std::cout << "ClapTrap " << this->name << " received " << amount << " damage and left with " << this->hp << " hp!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->hp == 0) {
		std::cout << this->name << " is knocked out x(\n";
	}
	else if (this->mana == 0) {
		std::cout << "No energy!\n";
	}
	else {
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " healed for " << amount << " hp, and have " << this->hp << " left!\n";
		this->mana--;
	}
}