#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		void highFivesGuys(void);
};

#endif