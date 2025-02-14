#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << B_G "Default constructor of Bureaucrat called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name, int grade)
{
	std::cout << B_G "Constructor of Bureaucrat called" RESET << std::endl;
	this->_Name = name;
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_Grade = grade;  //<<<<< GERER LES THRO/CATCH POUR LES EXCEPTIONS !
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << B_G "Copy Constructor of Bureaucrat called" RESET << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << B_R "Destructor of Bureaucrat called" RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &second)
{
	std::cout << B_G "Surcharge operator ""="" of Bureaucrat called" RESET << std::endl;
	this->_Name = second.getName();
	this->_Grade = second.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_Name);
}

int Bureaucrat::getGrade() const
{
	return (this->_Grade);
}

const char *Bureaucrat::GradeTooHighException::what () const throw()
{
	return ("grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &output,Bureaucrat const &_Bureaucrat)
{
	output << B_Y<< _Bureaucrat.getName() << B_M ", bureaucrat grade " B_Y << _Bureaucrat.getGrade() << RESET << std::endl; 
	return (output);
}