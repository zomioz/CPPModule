#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		ShrubberyCreationForm();
		std::string _Target;
	public :
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &second);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif