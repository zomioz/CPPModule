#include "Character.hpp"

Character::Character()
{
	std::cout << B_G "Default Constructor of Character called" RESET << std::endl;
}

Character::Character(std::string name)
{
	this->_Name = name;
	for (int i = 0; i < 4; i++)
	{
		this->Iventory[i] = 0;
	}
	std::cout << B_G "Constructor of " B_Y << this->_Name << B_G " Character called" RESET << std::endl;
}

Character::Character(const Character &copy)
{
	this->_Name = copy.getName();
	std::cout << B_G "Copy Constructor of " B_Y <<  this->_Name << B_G " Character called" RESET << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (copy.Iventory[x] != 0)
		{
			if (copy.Iventory[x]->getType() == "ice")
				this->Iventory[x] = new Ice();
			else if (copy.Iventory[x]->getType() == "cure")
				this->Iventory[x] = new Cure();
		}
	}
}

Character::~Character()
{
	std::cout << B_R "Destructor of " B_Y << this->_Name << B_R " Character called" RESET << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (this->Iventory[x] != 0)
			delete this->Iventory[x];
	}
}

Character &Character::operator=(const Character &second)
{
	this->_Name = second.getName();
	std::cout << B_B "Surchage operator ""="" of " B_Y << this->_Name << B_B " Character has been called" RESET  << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (this->Iventory[x] != 0)
		{
			delete this->Iventory[x];
			this->Iventory[x] = 0;
		}
	}
	for (int x = 0; x < 4; x++)
	{
		if (second.Iventory[x] != 0)
		{
			if (second.Iventory[x]->getType() == "ice")
				this->Iventory[x] = new Ice();
			else if (second.Iventory[x]->getType() == "cure")
				this->Iventory[x] = new Cure();
		}
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->_Name);
}

void Character::equip(AMateria *m)
{
	if (m)
	{
		int	x = 0;
		while (x < 4 && this->Iventory[x] != 0)
			x++;
		if (x < 4)
		{
			this->Iventory[x] = m;
			std::cout << "new AMateria equiped" << std::endl;
		}
		else
			std::cout << "Can't equipe this AMateria, Iventory maybe full ?" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		if (this->Iventory[idx] != 0)
			this->Iventory[idx] = 0;
		std::cout << "Character unequiped slot " << idx << std::endl;
		return ;
	}
	std::cout << "Character don't have large pocket, only 4 slots [0-4] !" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0)
	{
		if (this->Iventory[idx] == 0)
			std::cout << "Character can't use an empty slot" << std::endl;
		else if (this->Iventory[idx]->getType() == "cure")
			this->Iventory[idx]->use(target);
		else if (this->Iventory[idx]->getType() == "ice")
			this->Iventory[idx]->use(target);
		return ;
	}
	std::cout << "Character don't have large pocket, only 4 slots [0-4] !" << std::endl;
}