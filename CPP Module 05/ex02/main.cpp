#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>TEST SURCHARGE OPERATOR ET COPY CONSRTUCTOR<<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/* {
		std::string Albert = "Albert";
		std::string John = "John";

		RobotomyRequestForm Form_Albert(Albert);
		std::cout << std::endl << Form_Albert << std::endl << std::endl;

		RobotomyRequestForm Form_John(John);
		std::cout << std::endl << Form_John << std::endl << std::endl << B_B "Creating a copy of Form_John." RESET << std::endl;

		RobotomyRequestForm Copy_Form_John(Form_John);
		std::cout << std::endl << Copy_Form_John << std::endl << std::endl << B_B "Now Copy_Form_John will become a Copy_Form_Albert." RESET << std::endl;

		Copy_Form_John = Form_Albert;
		std::cout << std::endl << Copy_Form_John << std::endl << std::endl;
	} */



	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>TESTS FOR CREATE FORM, BUREAUCRAT AND EXECUTE IT<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

	//Presidential Form
	{
		std::string Name_Albert = "Albert";
		std::string Name_John = "John";
		std::string Target_Form = "Target"; // << Change Target here to see the target is right

		std::cout << B_B "Creation of Bureaucrat and Form" RESET << std::endl << std::endl;
		Bureaucrat Albert(Name_Albert, 1); // << Change Grade here to see every error handeling
		Bureaucrat John(Name_John, 150);
		PresidentialPardonForm test(Target_Form);
		std::cout << test;
		std::cout << std::endl << std::endl;

		std::cout << B_B "Try to execute an unsigned form" RESET << std::endl << std::endl;
		Albert.executeForm(test);

		std::cout << std::endl << std::endl << B_B "Albert sign form, and both try to execute it" RESET << std::endl << std::endl;
		Albert.signForm(test);
		std::cout << std::endl;
		John.executeForm(test);
		std::cout << std::endl;
		Albert.executeForm(test);
		std::cout << std::endl << std::endl;
	}

	//Robotomy Form
	/* {
		std::string Name_Albert = "Albert";
		std::string Name_John = "John";
		std::string Target_Form = "Target"; // << Change Target here to see the target is right

		std::cout << B_B "Creation of Bureaucrat and Form" RESET << std::endl << std::endl;
		Bureaucrat Albert(Name_Albert, 1); // << Change Grade here to see every error handeling
		Bureaucrat John(Name_John, 150);
		RobotomyRequestForm test(Target_Form);
		std::cout << test;
		std::cout << std::endl << std::endl;

		std::cout << B_B "Try to execute an unsigned form" RESET << std::endl << std::endl;
		Albert.executeForm(test);

		std::cout << std::endl << std::endl << B_B "Albert sign form, and both try to execute it" RESET << std::endl << std::endl;
		Albert.signForm(test);
		std::cout << std::endl;
		John.executeForm(test);
		std::cout << std::endl;
		Albert.executeForm(test);
		std::cout << std::endl << std::endl;
	} */

	//Shrubbery Form
	/* {
		std::string Name_Albert = "Albert";
		std::string Name_John = "John";
		std::string Target_Form = "yolo"; // << Change Target here to see the target is right

		std::cout << B_B "Creation of Bureaucrat and Form" RESET << std::endl << std::endl;
		Bureaucrat Albert(Name_Albert, 1); // << Change Grade here to see every error handeling
		Bureaucrat John(Name_John, 150);
		ShrubberyCreationForm test(Target_Form);
		std::cout << test;
		std::cout << std::endl << std::endl;

		std::cout << B_B "Try to execute an unsigned form" RESET << std::endl << std::endl;
		Albert.executeForm(test);

		std::cout << std::endl << std::endl << B_B "Albert sign form, and both try to execute it" RESET << std::endl << std::endl;
		Albert.signForm(test);
		std::cout << std::endl;
		John.executeForm(test);
		std::cout << std::endl;
		Albert.executeForm(test);
		std::cout << std::endl << std::endl;
	} */
	return 0;
}