#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>TEST SURCHARGE OPERATOR ET COPY CONSRTUCTOR<<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/* {
		Intern test = Intern();
		Intern test2(test);
		test = test2;
	} */

	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>>>>>>>>TESTS FOR CREATE INTER AND FORM<<<<<<<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	{
		std::string Albert_name = "Albert";
		Bureaucrat Albert(Albert_name, 1);
		Intern RandomInter = Intern();
		AForm* temp;
		std::cout << std::endl << std::endl;

		try
		{
			temp = RandomInter.makeForm("blablabla", "Target");
		}
		catch (Intern::FormDoesntExist &e) {std::cout << B_B << e.what() << RESET << std::endl;};

		std::cout << std::endl << std::endl;

		try 
		{
			temp = RandomInter.makeForm("Presidential", "Target");
			Albert.signForm(*temp);
			Albert.executeForm(*temp);
			delete (temp);
		}
		catch (Intern::FormDoesntExist &e) {std::cout << B_B << e.what() << RESET << std::endl;};

		std::cout << std::endl << std::endl;

		try
		{
			temp = RandomInter.makeForm("Robotomy", "Target");
			Albert.signForm(*temp);
			Albert.executeForm(*temp);
			delete (temp);
		}
		catch (Intern::FormDoesntExist &e) {std::cout << B_B << e.what() << RESET << std::endl;};

		std::cout << std::endl << std::endl;

		try 
		{
			temp = RandomInter.makeForm("Shrubbery", "Target");
			Albert.signForm(*temp);
			Albert.executeForm(*temp);
			delete(temp);
		}
		catch (Intern::FormDoesntExist &e) {std::cout << B_B << e.what() << RESET << std::endl;};
	}
	
	return 0;
}