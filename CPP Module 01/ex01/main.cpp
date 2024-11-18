#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int	main(void)
{
	//int N = -1;
	//int N = 0;
	//int N = 9999999;
	int N = 10;
	Zombie *test = zombieHorde(N, "Bob");
	if (!test)
		return (1);
	for (int i = 0; i < N; i++)
		test[i].announce();
	delete [] test;
	return (0);
}