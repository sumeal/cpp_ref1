#include "Zombie.hpp"

int main() {
	int N = 9;
	Zombie* many = zombieHorde(N, "Muzz");
	for (int i = 0; i < N; i++)
		many[i].announce();
	delete[] many;
	return 0;
}