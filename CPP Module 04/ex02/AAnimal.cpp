#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << B_G "Constructor of AAnimal has been called" RESET << std::endl;
	this->setType("An undefined Form");
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << B_G "copy Constructor of AAnimal has been called" RESET << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << B_R "Destructor of AAnimal has been called" RESET  << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &second)
{
	std::cout << B_R "Surchage operator ""="" of AAnimal has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}

void	AAnimal::setType(const std::string &param)
{
	this->type = param;
}

std::string AAnimal::getType() const
{
	return (this->type);
}