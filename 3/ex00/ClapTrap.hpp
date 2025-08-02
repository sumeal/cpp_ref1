#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
	private :
		unsigned int hp;
		unsigned int mana;
		unsigned int att;
		std::string name;
	
	public :
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
};

#endif