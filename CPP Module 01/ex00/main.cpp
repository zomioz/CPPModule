#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	std::string bob = "Bob";
	Zombie *test = newZombie(bob);
	randomChump("Daniel");
	test->announce();
	delete test;
	return (0);
}	