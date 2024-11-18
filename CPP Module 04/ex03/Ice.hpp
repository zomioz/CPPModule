#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice &operator=(const Ice &second);
		virtual AMateria* clone() const;
};

#endif