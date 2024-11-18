#include "ScavTrap.hpp"

void	PrintValue_Scavtrap(ClapTrap &CT)
{
	std::cout << B_M "Name : " RESET << CT.getName() << std::endl;
	std::cout << B_R "❤️ Hit Points : " RESET << CT.getHitPoints() << std::endl;
	std::cout << B_Y "⚡Energy Points : " RESET << CT.getEnergyPoints() << std::endl;
	std::cout << B_M "⚔️ Attack Damage : " RESET << CT.getAttackDamage() << std::endl;
}

int	main(void)
{
	ScavTrap a("bob");
	ScavTrap b("Daniel");
	ScavTrap c(a);
	ScavTrap d("test");
	d = b;

	std::cout << B_Y "ScavTrap A = " RESET << std::endl;
	PrintValue_Scavtrap(a);
	std::cout << B_Y "ScavTrap B = " RESET << std::endl;
	PrintValue_Scavtrap(b);
	std::cout << B_Y "ScavTrap C = " RESET << std::endl;
	PrintValue_Scavtrap(c);
	std::cout << B_Y "ScavTrap D = " RESET << std::endl;
	PrintValue_Scavtrap(d);
	std::cout << std::endl;


	//TEST FOR ATTACK()
	std::cout << "TEST FOR ATTACK() " << std::endl;
	a.attack("Jean-Mi");
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 4; i >= 0; i--)
	{
		b.attack("Flute");
		std::cout << std::endl;
	}
	b.setAttackDamage(23);
	for (int i = 4; i >= 0; i--)
	{
		b.attack("Lutte");
		std::cout << std::endl;
	}
	std::cout << B_Y "ScavTrap A = " RESET << std::endl;
	PrintValue_Scavtrap(a);
	std::cout << B_Y "ScavTrap B = " RESET << std::endl;
	PrintValue_Scavtrap(b);
	std::cout << std::endl;
	std::cout << std::endl;

	//TEST FOR BEREPAIRED()
	std::cout << "TEST FOR BEREPAIRED() " << std::endl;
	a.takeDamage(80);
	std::cout << std::endl;
	a.beRepaired(70);
	std::cout << std::endl;
	std::cout << std::endl;
	b.takeDamage(30);
	std::cout << std::endl;
	for (int i = 10; i >= 5; i--)
	{
		b.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << B_Y "ScavTrap A = " RESET << std::endl;
	PrintValue_Scavtrap(a);
	std::cout << B_Y "ScavTrap B = " RESET << std::endl;
	PrintValue_Scavtrap(b);
	std::cout << std::endl;
	//KEEPER MODE
	a.guardGate();
	a.guardGate();
}