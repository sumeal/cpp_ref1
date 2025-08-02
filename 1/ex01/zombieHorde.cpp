#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie* group = new Zombie[N];
	for(int i = 0; i < N; i++)
		group[i].setName(name);
	return group;
}