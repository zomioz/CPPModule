#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define RESET "\x1B[0m"

class Zombie {
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void	set_name(std::string name);
		void	announce(void);
	private:
		std::string name;
};
#endif