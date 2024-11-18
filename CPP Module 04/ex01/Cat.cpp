#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat():Animal()
{
	std::cout << B_G "Constructor of Cat has been called" RESET << std::endl;
	this->setType("Cat");
	this->_Brain = new Brain();
	this->_Brain->setIdeas("I'm a cat , I'm upon you human");
}

Cat::Cat(const Cat &copy):Animal()
{
	std::cout << B_G "copy Constructor of Cat has been called" RESET << std::endl;
	this->_Brain = new Brain(copy.getBrain());
	
}

Cat::~Cat()
{
	std::cout << B_R "Destructor of Cat has been called" RESET << std::endl;
	delete this->_Brain;
}

Cat	&Cat::operator=(const Cat &second)
{
	std::cout << B_R "Surchage operator ""="" of Cat has been called" RESET  << std::endl;
	this->setType(second.getType());
	delete this->_Brain;
	this->_Brain = new Brain(second.getBrain());
	this->_Brain->setIdeas(second._Brain->getIdeas());
	return (*this);
}

Brain	Cat::getBrain() const
{
	return (*this->_Brain);
}