#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->keeper = false;
	std::cout << B_G "Constructor of ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << B_R "Destructor of ScavTrap called" RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy)
{
	std::cout << B_G "Copy Constructor of ScavTrap called" RESET << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &second)
{
	std::cout << B_B "ScavTrap Surchage operator called" RESET << std::endl;
	this->setName(second.getName());
	this->setHitPoints(second.getHitPoints());
	this->setEnergyPoints(second.getEnergyPoints());
	this->setAttackDamage(second.getAttackDamage());
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << B_Y << this->getName() << B_R " ScavTrap is dead, he can't attack anymore" RESET << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << B_Y << this->getName() << B_R " ScavTrap doesn't have Energy points left, he can't attack anymore" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << B_M "ScavTrap " B_B "|" B_Y << this->getName() << B_M " ⚔️ -attacks-⚔️  " B_Y << target << B_B "|" B_M " ,causing " B_Y << this->getAttackDamage() << B_Y " points of damage !" RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->keeper == false)
	{
		this->keeper = true;
		std::cout << B_M "ScavTrap : " << B_Y << this->getName() << B_M " activate his keeper mode !" RESET << std::endl;
	}
	else
	{
		this->keeper = false;
		std::cout << B_M "ScavTrap : " << B_Y << this->getName() << B_M " desactivate his keeper mode !" RESET << std::endl;
	}

}