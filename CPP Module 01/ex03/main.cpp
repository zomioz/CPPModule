#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		std::string name = "Bob";
		std::string weapon = "crude spiked club";
		Weapon club = Weapon(weapon);
		HumanA bob(name, club);
		bob.attack();
		weapon = "some other type of club";
		club.setType(weapon);
		bob.attack();
	}
	{
		std::cout << std::endl << std::endl;
		std::string name = "Jim";
		std::string weapon = "crude spiked club";
		Weapon club = Weapon(weapon);
		HumanB jim(name);
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		weapon = "some other type of club";
		club.setType(weapon);
		jim.attack();
	}
	return (0);
}