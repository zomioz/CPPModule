#include "Ice.hpp"

Ice::Ice():AMateria()
{
	std::cout << B_G "Default Constructor of Ice called" RESET << std::endl;
	this->_Type = "ice";
}

Ice::Ice(const Ice &copy):AMateria()
{
	*this = copy;
	std::cout << B_G "Copy Constructor of Ice called" RESET << std::endl;
}

Ice &Ice::operator=(const Ice &second)
{
	std::cout << B_B "Surchage operator ""="" of Ice has been called" RESET  << std::endl;
	this->_Type = second.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << B_R "Destructor of Ice has been called" RESET << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << B_B "Clone fonction of Ice has been called" RESET  << std::endl;
	return (new Ice());
}