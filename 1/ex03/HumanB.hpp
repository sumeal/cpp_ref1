#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		void attack() const;
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
	private: 
		std::string name;
		Weapon* weapon;
};

#endif
