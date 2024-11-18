#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << B_G "Default Constructor of AMateria called" << std::endl;
}

AMateria::AMateria(const std::string &type)
{
	std::cout << B_G "Constructor of AMateria called" << std::endl;
	this->_Type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
	std::cout << B_G "Copy Constructor of AMateria called" RESET  << std::endl;
}

AMateria::~AMateria()
{
	std::cout << B_R "Destructor of AMateria called" RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &second)
{
	std::cout << B_B "Surchage operator ""="" of AMateria has been called" RESET  << std::endl;
	this->_Type = second.getType();
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_Type);
}

void AMateria::use(ICharacter &target)
{
	if (this->_Type == "cure")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_Type == "ice")
		std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
	return ;
}