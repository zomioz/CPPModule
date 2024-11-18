#include "Weapon.hpp"

Weapon::Weapon(std::string &type)
{
	this->type = type;
	std::cout << B_G "Weapon : " << B_Y << this->type << B_G " has been created" << RESET << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << B_R "Weapon : " << B_Y << this->type << B_R " has been destroyed"<< RESET << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string &type)
{
	std::cout << B_C "Weapon : " << B_Y << this->type << B_M " will change his type," << RESET;
	this->type = type;
	std::cout << B_M " Its now : " << B_Y << this->type << std::endl;
}