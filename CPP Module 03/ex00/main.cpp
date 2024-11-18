#include "ClapTrap.hpp"


void	PrintValue_Claptrap(ClapTrap &CT)
{
	std::cout << B_M "Name : " RESET << CT.getName() << std::endl;
	std::cout << B_R "❤️ Hit Points : " RESET << CT.getHitPoints() << std::endl;
	std::cout << B_Y "⚡Energy Points : " RESET << CT.getEnergyPoints() << std::endl;
	std::cout << B_M "⚔️ Attack Damage : " RESET << CT.getAttackDamage() << std::endl;
}

int	main(void)
{
	ClapTrap a("BoB");
	ClapTrap b("Daniel");
	ClapTrap c(a);
	ClapTrap d("TEST");
	d = b;

	std::cout << B_Y "ClapTrap A = " RESET << std::endl;
	PrintValue_Claptrap(a);
	std::cout << std::endl << std::endl;
	std::cout << B_Y "ClapTrap B = " RESET << std::endl;
	PrintValue_Claptrap(b);
	std::cout << std::endl << std::endl;
	std::cout << B_Y "ClapTrap C = " RESET << std::endl;
	PrintValue_Claptrap(c);
	std::cout << std::endl << std::endl;
	std::cout << B_Y "ClapTrap D = " RESET << std::endl;
	PrintValue_Claptrap(d);
	std::cout << std::endl << std::endl;

	//TEST FOR attack
	b.setAttackDamage(3);
	a.attack("Jean-Mi");
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 4; i >= 0; i--)
	{
		b.attack("Flute");
		std::cout << std::endl;
	}

	std::cout << B_Y "ClapTrap A = " RESET << std::endl;
	PrintValue_Claptrap(a);
	std::cout << std::endl << std::endl;
	std::cout << B_Y "ClapTrap B = " RESET << std::endl;
	PrintValue_Claptrap(b);
	std::cout << std::endl << std::endl;

	//TEST FOR BeRepaired()
	a.takeDamage(8);
	std::cout << std::endl;
	a.beRepaired(10);
	std::cout << std::endl;
	b.takeDamage(8);
	std::cout << std::endl;
	for (int i = 10; i >= 5; i--)
	{
		b.beRepaired(1);
		std::cout << std::endl;
	}

	std::cout << B_Y "ClapTrap A = " RESET << std::endl;
	PrintValue_Claptrap(a);
	std::cout << std::endl << std::endl;
	std::cout << B_Y "ClapTrap B = " RESET << std::endl;
	PrintValue_Claptrap(b);
	std::cout << std::endl << std::endl;
}