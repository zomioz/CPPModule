#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	std::cout << B_G "Default constructor of PresidentialPardonForm called" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5)
{
	std::cout << B_G "Constructor of PresidentialPardonForm called" RESET << std::endl;
	this->_Target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{ 
	std::cout << B_G "Copy Constructor of PresidentialPardonForm called" RESET << std::endl;
	this->_Target = copy._Target;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &second)
{
	std::cout << B_G "Surcharge operator ""="" of PresidentialPardonForm called" RESET << std::endl;
	 this->_Target = second._Target;
	 return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << B_R "Destructor of PresidentialPardonForm called" RESET << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AFormAlreadySigned());
	if (this->getRExecute() >= executor.getGrade())
		std::cout << B_Y << _Target << B_M " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
	else
		throw (GradeTooLowException());
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_Target);
}