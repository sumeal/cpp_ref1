#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hp = FragTrap::hp;
	this->mana = ScavTrap::mana;
	this->att = ScavTrap::att;
	std::cout << "DiamondTrap Constructor Called\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor Called\n";
}

DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	(void)other;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}