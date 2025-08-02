#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hp = 100;
	this->mana = 50;
	this->att = 20;
	std::cout << "ScavTrap Constructor Called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called\n";
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(name) {
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap Copy assignment called\n";
	(void)other;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << this->name << " is knocked out x(\n";
	}
	else if (this->mana == 0) {
		std::cout << "No energy!\n";
	}
	else {
		std::cout << "ScavTrap " << this->name << " FURIOUSLY attacks " << target << ", causing " << this->att << " points of damage!\n";
		this->mana--;
	}
}
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in gate keeper mode\n";
}