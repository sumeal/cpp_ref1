#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	// ClapTrap a("Muzz");
	// a.attack("Ahmad");
	// a.takeDamage(9);
	// a.beRepaired(1);
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.attack("no one!");
	// a.takeDamage(1);
	// a.takeDamage(1);
	// a.attack("Ahmad");
	// a.beRepaired(9);
	ScavTrap scavver("scavver");

	scavver.guardGate();
	scavver.attack("the air");
	scavver.takeDamage(1);
	scavver.beRepaired(100);
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.takeDamage(10000);
	scavver.attack("something");
	return 0;
}