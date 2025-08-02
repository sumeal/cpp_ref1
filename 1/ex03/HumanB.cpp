#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: weapon(NULL)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const{
	if (this->weapon)
		std::cout << this->name << " attack with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack" << std::endl;

}
