#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string &name)
{
	this->name = name;
	this->Weapon = 0;
	std::cout << B_G "HumanB has been created, his name is : " << B_Y << this->name << B_G " He doesn't have weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << B_R "HumanB has been destroyed, his name was : " << B_Y << this->name << RESET << std::endl;
}

void	HumanB::attack(void)
{
	if (!this->Weapon)
		std::cout << B_Y << this->name << B_C " attacks with their " << B_Y "Bare Hands" << RESET << std::endl;
	else
		std::cout << B_Y << this->name << B_C " attacks with their " << B_Y << this->Weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(class Weapon &Weapon)
{
	this->Weapon = &Weapon;
	std::cout << B_Y << this->name << B_C " get as weapon : " << B_Y << this->Weapon->getType() << RESET << std::endl;
}