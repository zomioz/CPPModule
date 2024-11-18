#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << B_R "Please Enter one argument (Harl Filter)" << RESET << std::endl;
		return (1);
	}
	Harl Bob;
	Bob.complain(argv[1]);
	return (0);
}