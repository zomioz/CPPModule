#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	private :
		std::string name;
		Weapon	*Weapon;
	public :
		HumanB(std::string &name);
		~HumanB();
		void	attack(void);
		void	setWeapon(class Weapon &Weapon);
};
#endif