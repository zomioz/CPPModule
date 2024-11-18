#include "Cat.hpp"

Cat::Cat():Animal()
{
	std::cout << B_G "Constructor of Cat has been called" RESET << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &copy):Animal()
{
	std::cout << B_G "copy Constructor of Cat has been called" RESET << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << B_R "Destructor of Cat has been called" RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &second)
{
	std::cout << B_R "Surchage operator ""="" of Cat has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}