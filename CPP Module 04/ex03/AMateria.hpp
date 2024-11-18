#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

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

class AMateria
{
	protected:
		AMateria();
		std::string _Type;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria	&operator=(const AMateria &second);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

};

#endif