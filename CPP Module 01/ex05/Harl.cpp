#include "Harl.hpp"

Harl::Harl()
{
	std::cout << B_G "Wild Harl appeared" << RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << B_R "Wild Harl desappeared" << RESET << std::endl;
}

void	Harl::debug(void)
{
	std::cout << B_Y "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << B_C "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << B_M "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << B_C "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*Complains[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string index[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;
	while (i < 4)
	{
		if (index[i] == level)
		{
			(this->*Complains[i])();
			break ;
		}
		i++;
	}
	if (i == 4)
		std::cout << B_R "Harl doesn't understand : " << B_Y << level << B_R << ". Please enter valid Input for Harl" << std::endl;
}