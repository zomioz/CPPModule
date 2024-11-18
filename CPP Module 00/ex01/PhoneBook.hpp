#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

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

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		int	add();
		int	search();
		void	contact_selected(int check);
	private:
		int		index;
		int		number_of_contact;
		Contact contact_list[8];
};

#endif