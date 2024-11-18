#include "Dog.hpp"

Dog::Dog():Animal()
{
	std::cout << B_G "Constructor of Dog has been called" RESET << std::endl;
	this->setType("Dog");
	this->_Brain = new Brain();
	this->_Brain->setIdeas("I'm a dog , I'm your best friend human");
}

Dog::Dog(const Dog &copy):Animal()
{
	std::cout << B_G "copy Constructor of Dog has been called" RESET << std::endl;
	this->_Brain = new Brain(copy.getBrain());
}

Dog::~Dog()
{
	std::cout << B_R "Destructor of Dog has been called" RESET << std::endl;
	delete this->_Brain;
}

Dog	&Dog::operator=(const Dog &second)
{
	std::cout << B_M "Surchage operator ""="" of Dog has been called" RESET  << std::endl;
	this->setType(second.getType());
	delete this->_Brain;
	this->_Brain = new Brain(second.getBrain());
	this->_Brain->setIdeas(second._Brain->getIdeas());
	return (*this);
}

Brain	Dog::getBrain() const
{
	return (*this->_Brain);
}