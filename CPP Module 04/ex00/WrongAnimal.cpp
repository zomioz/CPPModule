#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << B_G "Constructor of WrongAnimal has been called" RESET << std::endl;
	this->setType("An undefined Form");
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << B_G "copy Constructor of WrongAnimal has been called" RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << B_R "Destructor of WrongAnimal has been called" RESET  << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &second)
{
	std::cout << B_R "Surchage operator ""="" of WrongAnimal has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}

void	WrongAnimal::setType(const std::string &param)
{
	this->type = param;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	if (getType() == "WrongCat")
		std::cout << B_Y "Wrong Miaou-Miaou-Miaou";
	else
		std::cout << B_Y "Strange Wrondsound from an undefinded WrongAnimal";
	std::cout << RESET << std::endl;
}