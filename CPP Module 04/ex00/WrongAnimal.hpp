#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "iostream"

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

class WrongAnimal
{
	public  :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &second);
		void setType(const std::string &param);
		std::string getType() const;
		void	makeSound() const;
	protected :
		std::string type;
};

#endif