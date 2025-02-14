#ifndef INTER_HPP
#define INTER_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &second);
		~Intern();
		AForm *makeForm(std::string name_form, std::string target_form);
		class FormDoesntExist : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

#endif