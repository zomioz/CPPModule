#include <iostream>
#include <string>

# define B_M  "\x1B[1;35m"
# define B_C  "\x1B[1;36m"
# define RESET "\x1B[0m"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << B_C << "The memory address of the string variable : " << B_M << &str << RESET << std::endl;
	std::cout << B_C << "The memory address held by stringPTR      : " << B_M << stringPTR << RESET << std::endl;
	std::cout << B_C << "The memory address held by stringREF      : " << B_M << &stringREF << RESET << std::endl;
	std::cout << std::endl;
	std::cout << B_C << "The value of the string variable  : " << B_M << str << RESET << std::endl;
	std::cout << B_C << "The value pointed to by stringPTR : " << B_M << *stringPTR << RESET << std::endl;
	std::cout << B_C << "The value pointed to by stringREF : " << B_M << stringREF << RESET << std::endl;
}