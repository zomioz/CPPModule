#include "Cure.hpp"

Cure::Cure():AMateria()
{
	std::cout << B_G "Default Constructor of Cure called" RESET << std::endl;
	this->_Type = "cure";
}

Cure::Cure(const Cure &copy):AMateria()
{
	*this = copy;
	std::cout << B_G "Copy Constructor of Cure called" RESET << std::endl;
}

Cure &Cure::operator=(const Cure &second)
{
	std::cout << B_B "Surchage operator ""="" of Cure has been called" RESET  << std::endl;
	this->_Type = second.getType();
	return (*this);
}

Cure::~Cure()
{
	std::cout << B_R "Destructor of Cure has been called" << RESET << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << B_B "Clone fonction of Cure has been called" RESET  << std::endl;
	return (new Cure());
}