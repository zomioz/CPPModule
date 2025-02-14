#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		Form();
		std::string	_Name;
		bool 				_Signed;
		int			_RSigned;
		int			_RExecute;
	public :
		Form(std::string &name, int RSigned, int RExecute);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &second);

		std::string getName() const;
		bool		getSigned() const;
		int	getRSigned() const;
		int	getRExecute() const;
		void beSigned(const Bureaucrat *bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();
		};
		class FormAlreadySigned : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const Form &_Form);

#endif