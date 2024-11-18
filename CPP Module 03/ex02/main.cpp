#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	PrintValue_Fragtrap(ClapTrap &CT)
{
	std::cout << B_M "Name : " RESET << CT.getName() << std::endl;
	std::cout << B_R "❤️ Hit Points : " RESET << CT.getHitPoints() << std::endl;
	std::cout << B_Y "⚡Energy Points : " RESET << CT.getEnergyPoints() << std::endl;
	std::cout << B_M "⚔️ Attack Damage : " RESET << CT.getAttackDamage() << std::endl;
}

int	main(void)
{
	FragTrap a("Bob");
	FragTrap b("Daniel");
	FragTrap c(a);
	FragTrap d("test");
	d = b;

	std::cout << B_Y "FragTrap A = " RESET << std::endl;
	PrintValue_Fragtrap(a);
	std::cout << B_Y "FragTrap B = " RESET << std::endl;
	PrintValue_Fragtrap(b);
	std::cout << B_Y "FragTrap C = " RESET << std::endl;
	PrintValue_Fragtrap(c);
	std::cout << B_Y "FragTrap D = " RESET << std::endl;
	PrintValue_Fragtrap(d);
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
	std::cout << B_Y "FragTrap A = " RESET << std::endl;
	PrintValue_Fragtrap(a);
	std::cout << B_Y "FragTrap B = " RESET << std::endl;
	PrintValue_Fragtrap(b);
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
	std::cout << B_Y "FragTrap A = " RESET << std::endl;
	PrintValue_Fragtrap(a);
	std::cout << B_Y "FragTrap B = " RESET << std::endl;
	PrintValue_Fragtrap(b);
	std::cout << std::endl;

	//HIGH FIVE GUYS
	a.highFivesGuys();
	b.highFivesGuys();
	std::cout << std::endl;
}