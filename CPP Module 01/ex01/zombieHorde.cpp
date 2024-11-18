#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0 || N > 1000000)
	{
		if (N <= 0)
			std::cout << B_R "The world can't create a zombie horde that got less than one zombie" RESET << std::endl;
		else
			std::cout << B_R "Create a such zombie horde will take to much time, please create a smaller one !" RESET << std::endl;
		return (NULL);
	}
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].set_name(name);
	return (Horde);
}
