#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << B_G "Constructor of ClapTrap called" RESET << std::endl;
	this->setName(name);
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
} 
ClapTrap::~ClapTrap()
{
	std::cout << B_R "Destructor of ClapTrap called" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << B_G "Copy Constructor of ClapTrap called" RESET << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &second)
{
	std::cout << B_B "Surchage operator called" RESET << std::endl;
	this->setName(second.getName());
	this->setHitPoints(second.getHitPoints());
	this->setEnergyPoints(second.getEnergyPoints());
	this->setAttackDamage(second.getAttackDamage());
	return (*this);
}

//GETTER & SETTER

std::string ClapTrap::getName() const
{
	return (this->_Name);
}

void	ClapTrap::setName(std::string name)
{
	this->_Name = name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_HitPoints);
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	this->_HitPoints = amount;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_EnergyPoints);
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_EnergyPoints = amount;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_AttackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
}

//FUNCTIONS

void	ClapTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << B_Y << this->getName() << B_R " is dead, he can't attack anymore" RESET << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << B_Y << this->getName() << B_R " doesn't have Energy points left, he can't attack anymore" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << B_M "ClapTrap " B_B "|" B_Y << this->getName() << B_M " ⚔️ -attacks-⚔️  " B_Y << target << B_B "|" B_M " ,causing " B_Y << this->getAttackDamage() << B_Y " points of damage !" RESET << std::endl;
}

void 		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << B_Y << this->getName() << B_R " is already dead, he can't receive damage anymore." RESET << std::endl;
		return ;
	}
	if (amount > this->getHitPoints())
	{
		std::cout << B_Y << this->getName() << B_R " take " B_Y << this->getHitPoints() << B_R " damage. This Damage cause the death of ClapTrap : " B_Y << this->getName() << std::endl;
		this->setHitPoints(this->getHitPoints() - amount);
		return ;
	}
	std::cout << B_R "ClapTrap " B_Y << this->getName() << B_R " take " B_Y << amount << B_R " damage. ❤️  Hit point left : " B_Y << this->getHitPoints() - amount << B_R " !" << RESET;
	if (this->getHitPoints() == 0)
		std::cout << B_R " This Damage cause the death of ClapTrap : " B_Y << this->getName() << std::endl;
	else
		std::cout << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << B_R "ClapTrap " B_Y << this->getName() << B_R " is dead, he can't repair anymore" RESET << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << B_R "ClapTrap " B_Y << this->getName() << B_R " doesn't have Energy points left, he can't repair anymore" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << B_B "ClapTrap " B_Y << this->getName() << B_B " repaired : " B_Y << amount << B_B " of Hit Points, he now has " B_Y << this->getHitPoints() << B_B " Hit Points." RESET << std::endl;
}