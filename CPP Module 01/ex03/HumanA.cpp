#include "HumanA.hpp"

HumanA::HumanA(std::string &name, class Weapon &Weapon) : name(name), Weapon(Weapon) {
	std::cout << B_G "HumanA has been created, his name is : " << B_Y << this->name << B_G " => gets as weapon : " << B_Y << Weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA()
{
	std::cout << B_R "HumanA has been destroyed, his name was : " << B_Y << this->name << RESET << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << B_Y << this->name << B_C " attacks with their " << B_Y << Weapon.getType() << RESET << std::endl;
}
