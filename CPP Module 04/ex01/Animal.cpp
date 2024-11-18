#include "Animal.hpp"

Animal::Animal()
{
	std::cout << B_G "Constructor of Animal has been called" RESET << std::endl;
	this->setType("An undefined Form");
}

Animal::Animal(const Animal &copy)
{
	std::cout << B_G "copy Constructor of Animal has been called" RESET << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << B_R "Destructor of Animal has been called" RESET  << std::endl;
}

Animal	&Animal::operator=(const Animal &second)
{
	std::cout << B_R "Surchage operator ""="" of Animal has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}

void	Animal::setType(const std::string &param)
{
	this->type = param;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound()
{
	if (getType() == "Cat")
		std::cout << B_Y "Miaou-Miaou-Miaou";
	else if (getType() == "Dog")
		std::cout << B_Y "Ouaf-Ouaf-Ouaf";
	else
		std::cout << B_Y "Strange sound from an undefinded animal";
	std::cout << std::endl;
}