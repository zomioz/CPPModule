#include "Form.hpp"

Form::Form()
{
	std::cout << B_G "Default constructor of Form called" RESET << std::endl;
}

Form::Form(std::string &name, int RSigned, int RExecute)
{
	std::cout << B_G "Constructor of Form called" RESET << std::endl;
	this->_Name = name;
	if (RSigned > 150 || RExecute > 150)
		throw(GradeTooLowException());
	if (RSigned < 1 || RExecute < 1)
		throw(GradeTooHighException());
	this->_RSigned = RSigned;
	this->_RExecute = RExecute;
	this->_Signed = false;
}

Form::Form(const Form &copy)
{
	std::cout << B_G "Copy Constructor of Form called" RESET << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout << B_R "Destructor of Form called" RESET << std::endl;
}

Form &Form::operator=(const Form &second)
{
	std::cout << B_G "Surcharge operator ""="" of Form called" RESET << std::endl;
	this->_Name = second.getName();
	this->_Signed = second.getSigned();
	this->_RSigned = second.getRSigned();
	this->_RExecute = second.getRExecute();
	return(*this);
}

std::string Form::getName() const
{
	return (this->_Name);
}

bool Form::getSigned() const
{
	return (this->_Signed);
}

int Form::getRSigned() const
{
	return(this->_RSigned);
}

int Form::getRExecute() const
{
	return (this->_RExecute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("(From Form) grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("(From Form) grade is too low");
}

const char *Form::FormAlreadySigned::what() const throw()
{
	return ("(From Form) Form is already signed");
}

void Form::beSigned(const Bureaucrat *bureaucrat)
{
	if (this->_Signed == true)
	{
		throw Form::FormAlreadySigned();
	}
	else if (bureaucrat->getGrade() <= this->getRSigned())
	{
		this->_Signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &output,Form const &_Form)
{
	output << B_M "Form name : " << B_Y << _Form.getName() << B_M << "." << std::endl;
	output << "Require a bureaucrat grade : " << B_Y << _Form.getRExecute() << B_M << " To be executed." << std::endl;
	output << "And a bureaucrat grade : " << B_Y << _Form.getRSigned() << B_M << " To be signed." << std::endl;
	output << "Is this Form signed ? 0 = No / 1 = Yes : " << B_Y << _Form.getSigned() << RESET << std::endl;
	return (output);
}

