#include "Dog.hpp"

Dog::Dog():Animal()
{
	std::cout << B_G "Constructor of Dog has been called" RESET << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &copy):Animal()
{
	std::cout << B_G "copy Constructor of Dog has been called" RESET << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << B_R "Destructor of Dog has been called" RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &second)
{
	std::cout << B_R "Surchage operator ""="" of Dog has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}