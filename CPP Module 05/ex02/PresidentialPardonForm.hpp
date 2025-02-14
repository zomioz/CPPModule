#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		PresidentialPardonForm();
		std::string _Target;
	public :
		PresidentialPardonForm(const std::string &name);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &second);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif