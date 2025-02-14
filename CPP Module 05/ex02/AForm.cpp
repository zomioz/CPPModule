#include "AForm.hpp"

AForm::AForm()
{
	std::cout << B_G "Default constructor of AForm called" RESET << std::endl;
}

AForm::AForm(const std::string &name, int RSigned, int RExecute)
{
	std::cout << B_G "Constructor of AForm called" RESET << std::endl;
	this->_Name = name;
	if (RSigned > 150 || RExecute > 150)
		throw(GradeTooLowException());
	if (RSigned < 1 || RExecute < 1)
		throw(GradeTooHighException());
	this->_RSigned = RSigned;
	this->_RExecute = RExecute;
	this->_Signed = false;
}

AForm::AForm(const AForm &copy)
{
	std::cout << B_G "Copy Constructor of AForm called" RESET << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &second)
{
	std::cout << B_G "Surcharge operator ""="" of AForm called" RESET << std::endl;
	this->_Name = second.getName();
	this->_Signed = second.getSigned();
	this->_RSigned = second.getRSigned();
	this->_RExecute = second.getRExecute();
	return(*this);
}

std::string AForm::getName() const
{
	return (this->_Name);
}

bool AForm::getSigned() const
{
	return (this->_Signed);
}

int AForm::getRSigned() const
{
	return(this->_RSigned);
}

int AForm::getRExecute() const
{
	return (this->_RExecute);
}

AForm::~AForm()
{
	std::cout << B_R "Destructor of AForm called" RESET << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("(From AForm) grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("(From AForm) grade is too low");
}

const char *AForm::AFormAlreadySigned::what() const throw()
{
	return ("(From AForm) Form is already signed");
}

void AForm::beSigned(const Bureaucrat *bureaucrat)
{
	if (this->_Signed == true)
	{
		throw AForm::AFormAlreadySigned();
	}
	else if (bureaucrat->getGrade() <= this->getRSigned())
	{
		this->_Signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &output,AForm const &_Form)
{
	output << B_M "Form name : " << B_Y << _Form.getName() << B_M << " And target is : " B_Y << _Form.getTarget() << B_M << std::endl;
	output << "Require a bureaucrat grade : " << B_Y << _Form.getRExecute() << B_M << " To be executed." << std::endl;
	output << "And a bureaucrat grade : " << B_Y << _Form.getRSigned() << B_M << " To be signed." << std::endl;
	output << "Is this Form signed ? 0 = No / 1 = Yes : " << B_Y << _Form.getSigned() << RESET << std::endl;
	return (output);
}