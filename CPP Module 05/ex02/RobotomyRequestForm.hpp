#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
		RobotomyRequestForm();
		std::string _Target;
	public :
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &second);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif