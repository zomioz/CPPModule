#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie tempo = Zombie(name);
	tempo.announce();
	return ;
}