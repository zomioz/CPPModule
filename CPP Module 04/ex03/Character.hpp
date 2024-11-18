#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character: public ICharacter
{
	private :
		std::string _Name;
		Character();
		AMateria *Iventory[4];
	public :
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &second);

		virtual const std::string &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};

#endif