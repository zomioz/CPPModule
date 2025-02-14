#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"


class AForm;

class Bureaucrat
{
	private:
		Bureaucrat();
		std::string _Name;
		int			_Grade;
	public:
		Bureaucrat(std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &second);
		std::string getName() const;
		int			getGrade() const;
		void signForm(AForm &check);
		void executeForm(AForm const &_form);
	class GradeTooHighException: public std::exception
	{
		public :
			const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public :
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &_Bureaucrat);

#endif