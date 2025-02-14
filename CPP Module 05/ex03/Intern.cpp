#include "Intern.hpp"

Intern::Intern()
{
	std::cout << B_G "Default constructor of Intern called" RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << B_G "Copy Constructor of Intern called" RESET << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &second)
{
	std::cout << B_G "Surcharge operator ""="" of Intern called" RESET << std::endl;
	(void)second;
	return (*this);
}

Intern::~Intern()
{
	std::cout << B_R "Destructor of Intern called" RESET << std::endl;
}

AForm *Intern::makeForm(std::string name_form, std::string target_form)
{
	std::string name[] = {"Presidential", "Robotomy", "Shrubbery"};
	for (int i = 0; i < 3; i++)
	{
		if (name_form == name[i])
		{
			std::cout << B_M "Intern creates " B_Y << name[i] << RESET << std::endl;
			switch (i)
			{
				case (0) :
					return (new PresidentialPardonForm(target_form));
				case (1) :
					return (new RobotomyRequestForm(target_form));
				case (2) :
					return (new  ShrubberyCreationForm(target_form));
			}
		}
	}
	throw (Intern::FormDoesntExist());
	return (0);
}

const char *Intern::FormDoesntExist::what() const throw()
{
	return ("Intern can't create a form that doesn't exist");
}