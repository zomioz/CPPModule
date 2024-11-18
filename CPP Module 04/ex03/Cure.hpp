#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &second);
		virtual AMateria* clone() const;
};

#endif