#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << B_G "Constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy)
{
	std::cout << B_G "Copy Constructor of FragTrap called" RESET << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << B_R "Destructor of FragTrap called" RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &second)
{
	std::cout << B_B "FragTrap Surchage operator called" RESET << std::endl;
	this->setName(second.getName());
	this->setHitPoints(second.getHitPoints());
	this->setEnergyPoints(second.getEnergyPoints());
	this->setAttackDamage(second.getAttackDamage());
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << B_B "FragTrap " B_Y << this->getName() << B_B " say : High Fives Guys ?" RESET << std::endl;
}