#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int x = 0; x < 4; x++)
		this->_Source[x] = 0;
	std::cout << B_G "Constructor of MateriaSource called" RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << B_G "Copy Constructor of MateriaSource called" RESET << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (copy._Source[x] != 0)
		{
			if (copy._Source[x]->getType() == "ice")
				this->_Source[x] = new Ice();
			else if (copy._Source[x]->getType() == "cure")
				this->_Source[x] = new Cure();
		}
		else
			this->_Source[x] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << B_R "Destructor of MateriaSource called" RESET << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (this->_Source[x] != 0)
			delete this->_Source[x];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &second)
{
	std::cout << B_B "Surchage operator ""="" of MateriaSource called" RESET << std::endl;
	for (int x = 0; x < 4; x++)
	{
		if (this->_Source[x] != 0)
		{
			delete this->_Source[x];
			this->_Source[x] = 0;
		}
	}
	for (int x = 0; x < 4; x++)
	{
		if (second._Source[x] != 0)
		{
			if (second._Source[x]->getType() == "ice")
				this->_Source[x] = new Ice();
			else if (second._Source[x]->getType() == "cure")
				this->_Source[x] = new Cure();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *mat)
{
	for (int x = 0; x < 4; x++)
	{
		if (this->_Source[x] == 0)
		{
			if (mat->getType() == "ice" || mat->getType() == "cure")
				this->_Source[x] = mat;
			std::cout << "MateriaSource learn a new Materia" << std::endl;
			return ;
		}
	}
	std::cout << "Knowledge of MateriaSource is full, it can't learns new Materia" << std::endl; 
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int x = 0; x < 4; x++)
	{
		if (this->_Source[x]->getType() == type)
		{
			if (type == "ice")
				return (new Ice());
			else if (type == "cure")
				return (new Cure());

		}
	}
	std::cout << "No match found for this type" << std::endl;
	return (NULL);
}