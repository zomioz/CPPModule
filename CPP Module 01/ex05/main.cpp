#include "Harl.hpp"

int	main(void)
{
	Harl Bob;

	std::cout << """DEBUG"" Input : ";
	Bob.complain("DEBUG");
	std::cout << """INFO"" Input : ";
	Bob.complain("INFO");
	std::cout << """WARNING"""" Input : ";
	Bob.complain("WARNING");
	std::cout << """ERROR"" Input : ";
	Bob.complain("ERROR");
	std::cout << std::endl << std::endl;
	std::cout << "Bad Input : ";
	Bob.complain("42");
	return (0);
}