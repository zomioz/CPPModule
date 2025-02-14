#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>TEST SURCHARGE OPERATOR ET COPY CONSRTUCTOR<<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// {
	// 	std::string str = "Jimmy";
	// 	std::string strr = "Form1";
	// 	Form paper(strr, 1, 1);
	// 	Bureaucrat boss(str, 150);

	// 	try
	// 	{
	// 		paper = Form(strr, 45, 45);
	// 		std::cout << paper;
	// 	}
	// 	catch (const Form::GradeTooLowException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	catch (const Form::GradeTooHighException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}

	// 	try 
	// 	{
	// 		Bureaucrat ultimate_boos(boss);
	// 		boss = Bureaucrat(str, 1);
	// 		std::cout << boss;
	// 	}
	// 	catch (const Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	catch (const Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	std::cout << paper;
	// 	std::cout << boss;
	// }





	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>CLASSICS TESTS FOR CREATE AND SIGNED FORM <<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	{
		std::string str = "Jimmy";
		std::string strr = "Form1";
		try
		{
			Bureaucrat boss(str, 1);
			std::cout << boss;
			Form paper(strr, 65, 65);
			std::cout << paper;
			boss.signForm(paper);
			boss.signForm(paper);
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << B_R << e.what() << RESET << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << B_R << e.what() << RESET << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cout << B_R << e.what() << RESET << std::endl;
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cout << B_R << e.what() << RESET << std::endl;
		}
	}




	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	/*>>>>>        ERROR HANDELLING FOR FORM         <<<<*/
	/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// {
	// 	std::string strr = "Form1";
	// 	try
	// 	{
	// 		Form paper(strr, 0, 65);
	// 		std::cout << paper;
	// 	}
	// 	catch (const Form::GradeTooLowException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	catch (const Form::GradeTooHighException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	try
	// 	{
	// 		Form paper(strr, 65, 0);
	// 		std::cout << paper;
	// 	}
	// 	catch (const Form::GradeTooLowException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	catch (const Form::GradeTooHighException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	try
	// 	{
	// 		Form paper(strr, 0, 0);
	// 		std::cout << paper;
	// 	}
	// 	catch (const Form::GradeTooLowException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// 	catch (const Form::GradeTooHighException &e)
	// 	{
	// 		std::cout << B_R << e.what() << RESET << std::endl;
	// 	}
	// }
	return 0;
}