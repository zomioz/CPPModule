#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private :
		std::string name;
		Weapon &Weapon;
	public :
		HumanA(std::string &name, class Weapon &Weapon);
		~HumanA();
		void	attack(void);
};

#endif