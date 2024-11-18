#include "PhoneBook.hpp"
#include "Contact.hpp"

void	Print_Welcome() {
	std::cout << B_G"_________Welcome to your PhoneBook_________" << RESET;
	std::cout << std::endl;
	std::cout << B_Y "A simple and rapid PhoneBook of 8 Contacts" << RESET;
	std::cout << std::endl;
	std::cout << B_Y"___________________________________________" << RESET;
	std::cout << std::endl;
	std::cout << B_M"Enter : ADD ⭢ To add a new contact" << RESET;
	std::cout << std::endl;
	std::cout << B_M"Enter : SEARCH ⭢ To see all the contacts" << RESET;
	std::cout << std::endl;
	std::cout << B_M"Enter : EXIT ⭢ To close the PhoneBook" << RESET;
	std::cout << std::endl;
	std::cout << std::endl;
}

int	main() {
	PhoneBook phone;
	std::string str;

	Print_Welcome();
	while (str != "EXIT")
	{
		std::cout << B_C"Enter a command :" << RESET << std::endl; 
		std::cin >> str;
		if (std::cin.eof())
			return (1);
		if (str == "ADD")
			if (phone.add() == 1)
				return (1);
		if (str == "SEARCH")
			if (phone.search() == 1)
				return (1);
	}
	std::cout << B_Y"See you soon !" << RESET << std::endl;
	return (0);
}