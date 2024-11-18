#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define B_C  "\x1B[1;36m"
# define RESET "\x1B[0m"

class Harl {
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		Harl();
		~Harl();
		void	complain(std::string level);
};
#endif
