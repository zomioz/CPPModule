#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << B_Y << this->name << B_G << " created" << RESET << std::endl;
}

Zombie::Zombie(void)
{
	this->name.clear();
	std::cout << B_G << "A new Zombie with no name has been created" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << B_R << "Zombie named : " << RESET << B_Y << this->name << RESET << B_R << " is definitely dead" << RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << B_Y << this->name << RESET << B_B << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	std::cout << B_G << "This Zombie's name is now : " << B_Y << this->name << RESET << std::endl;
}