#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal()
{
	std::cout << B_G "Constructor of WrongCat has been called" RESET << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &copy):WrongAnimal()
{
	std::cout << B_G "copy Constructor of WrongCat has been called" RESET << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << B_R "Destructor of WrongCat has been called" RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &second)
{
	std::cout << B_R "Surchage operator ""="" of WrongCat has been called" RESET  << std::endl;
	this->setType(second.getType());
	return (*this);
}