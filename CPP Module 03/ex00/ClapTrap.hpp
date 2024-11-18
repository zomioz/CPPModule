#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define R   "\x1B[31m"
# define G   "\x1B[32m"
# define Y   "\x1B[33m"
# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define B_C  "\x1B[1;36m"
# define BOLD "\x1B[1m"
# define RESET "\x1B[0m"

class ClapTrap{
	private :
		std::string _Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
	public :
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap (const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &second);
		//FONCTION
		void 		attack(const std::string &target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		//SETTER & GETTER
		std::string getName() const;
		void		setName(std::string name);
		unsigned int	getHitPoints() const;
		void			setHitPoints(unsigned int amount); 
		unsigned int	getEnergyPoints() const;
		void			setEnergyPoints(unsigned int amount);
		unsigned int	getAttackDamage() const;
		void			setAttackDamage(unsigned int amount);
};
#endif