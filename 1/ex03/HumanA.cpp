#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA (std::string name, Weapon& weapon) 
	: weapon(weapon)
{
	this->name = name;
}

void HumanA::attack() const{
	std::cout << this->name << " attack with " << this->weapon.getType() << std::endl;
}