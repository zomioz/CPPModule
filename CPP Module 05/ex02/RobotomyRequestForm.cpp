#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	std::cout << B_G "Default constructor of RobotomyRequestForm called" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45)
{
	std::cout << B_G "Constructor of RobotomyRequestForm called" RESET << std::endl;
	this->_Target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout << B_G "Copy Constructor of RobotomyRequestForm called" RESET << std::endl;
	this->_Target = copy._Target;
};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &second)
{
	std::cout << B_G "Surcharge operator ""="" of RobotomyRequestForm called" RESET << std::endl;
	this->_Target = second._Target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << B_R "Destructor of RobotomyRequestForm called" RESET << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AFormAlreadySigned());
	if (this->getRExecute() >= executor.getGrade())
	{
		std::cout << B_G "*Make some drilling noise*" << RESET << std::endl;
		srand(time(0));
		if ((rand() % 2) == 0)
			std::cout << B_Y << _Target << B_M " has been robotomized." << RESET << std::endl;
		else
			std::cout << B_M << "robotomize failed." RESET << std::endl; 
	}
	else
		throw (GradeTooLowException());
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_Target);
}