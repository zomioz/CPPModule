#include "Bureaucrat.hpp"

int	main(void)
{
	std::string str = "Jimmy";
	try 
	{
		Bureaucrat jimmy(str, 151);
		std::cout << jimmy;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	try 
	{
		Bureaucrat jimmy(str, 0);
		std::cout << jimmy;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	try 
	{
		Bureaucrat jimmy(str, 75);
		std::cout << jimmy;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << B_R << e.what() << RESET << std::endl;
	}
	return 0;
}