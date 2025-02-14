#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		AForm();
		std::string _Name;
		bool		_Signed;
		int			_RSigned;
		int			_RExecute;
	public :
		AForm(const std::string &name, int RSigned, int RExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &second);

		std::string getName() const;
		bool		getSigned() const;
		int			getRSigned() const;
		int			getRExecute() const;
		void		beSigned(const Bureaucrat *bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		virtual std::string getTarget() const = 0;
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
		class AFormAlreadySigned : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const AForm &_Form);

#endif