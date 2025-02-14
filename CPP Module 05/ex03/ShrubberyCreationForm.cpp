#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	std::cout << B_G "Default constructor of ShrubberyCreationForm called" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137)
{
	std::cout << B_G "Constructor of ShrubberyCreationForm called" RESET << std::endl;
	this->_Target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << B_G "Copy Constructor of ShrubberyCreationForm called" RESET << std::endl;
	this->_Target = copy._Target;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &second)
{
	std::cout << B_G "Surcharge operator ""="" of ShrubberyCreationForm called" RESET << std::endl;
	this->_Target = second._Target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << B_R "Destructor of ShrubberyCreationForm called" RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AFormAlreadySigned());
	if (this->getRExecute() >= executor.getGrade())
	{
		std::string filename = _Target + "_shrubbery";
        std::ofstream out(filename.c_str());
		out << "                   # #### ####\n";
        out << "                ### \\/#|### |/####\n";
        out << "               ##\\/#/ \\||/##/_/##/_#\n";
        out << "             ###  \\/###|/ \\/ # ###\n";
        out << "           ##_\\_#\\_\\## | #/###_/_####\n";
        out << "          ## #### # \\ #| /  #### ##/##\n";
        out << "           __#_--###`  |{,###---###-~\n";
        out << "                     \\ }{\n";
        out << "                      }}{\n";
        out << "                      }}{\n";
        out << "                 ejm  {{}\n";
        out << "                , -=-~{ .-^- _\n";
        out << "                      {`}\n";
                                       

        out.close();
        std::cout << B_M  "A tree has been generated in " << B_Y << filename << RESET << std::endl;
	}
	else
		throw (GradeTooLowException());
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_Target);
}