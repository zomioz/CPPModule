#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	index = 0;
	number_of_contact = 0;
}

PhoneBook::~PhoneBook() {
}

int	verif_space(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

std::string get_user_input() {
	std::string str;
	std::getline(std::cin, str); 
	while (str.size() == 0 || verif_space(str) != 1)
	{
		if (std::cin.eof())
		{
			str.clear();
			return (str);
		}
		std::getline(std::cin, str);
	}
	return (str);
}

int	PhoneBook::add() {
	std::string str;
	if (number_of_contact == 8)
	{
		if (index != 8)
			std::cout << B_R"Watch out , DATA from the contact: " << index + 1 << " will be overwrite ! Do you want to continue ? Yes/No" << RESET << std::endl;
		else
			std::cout << B_R"Watch out , DATA from the first contact will be overwrite ! Do you want to continue ? Yes/No" << RESET << std::endl;
		str = get_user_input();
		if (str.size() == 0)
			return (1);
		while (str != "Yes" && str != "No")
		{
			str = get_user_input();
			if (str.size() == 0)
				return (1);
		}
		if (str == "Yes")	
		{
			std::cout << B_R"Contact erased" << RESET << std::endl;
			if (index == 8)
				index = 0;
		}
		else
			return (0);
	}
	std::cout << Y"Enter your FIRST NAME\n" << RESET;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	contact_list[index].set_first_name(str);
	std::cout << Y"Enter your LAST NAME\n" << RESET;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	contact_list[index].set_last_name(str);
	std::cout << Y"Enter your NICKNAME\n" << RESET;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	contact_list[index].set_nickname(str);
	std::cout << Y"Enter your PHONE_NUMBER\n" << RESET;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	contact_list[index].set_phone_number(str);
	std::cout << Y"Enter your DARKEST SECRET\n" << RESET;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	contact_list[index].set_darkest_secret(str);
	index++;
	if (number_of_contact < 8)
		number_of_contact++;
	return (0);
}

void	print_data(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.push_back('.');
	}
	std::cout << std::setw(10) << str;
}
void	PhoneBook::contact_selected(int check) {
	std::cout << std::endl;
	std::cout << B_M"You choose contact number : " << check + 1 << RESET << std::endl;
	std::cout << B_C"First Name : " << contact_list[check].get_first_name() << RESET << std::endl;
	std::cout << B_C"Last Name : " << contact_list[check].get_last_name() << RESET << std::endl;
	std::cout << B_C"Nikname :  " << contact_list[check].get_nickname() << RESET << std::endl;
	std::cout << B_C"Phone Number : " << contact_list[check].get_phone_number() << RESET << std::endl;
	std::cout << B_C"Darkest Secret : " << contact_list[check].get_darkest_secret() << RESET << std::endl;
}

int	PhoneBook::search() {
	int	i = 0;

	if (number_of_contact == 0)
	{
		std::cout << B_R"Please Enter a valid contact before display your PhoneBook !" << RESET << std::endl;
		return (0);
	}
	std::cout << "Your PhoneBook :" << std::endl;
	std::cout << B_B"_____________________________________________" << RESET << std::endl;
	std::cout << B_B"|" << B_M << std::setw(10) << "Index" << RESET << B_B"|" << RESET;
	std::cout << B_M << std::setw(10) << "First Name" << RESET << B_B"|" << RESET;
	std::cout << B_M << std::setw(10) << "Last Name" << RESET << B_B"|" << RESET;
	std::cout << B_M << std::setw(10) << "Nickname" << RESET << B_B"|" << RESET << std::endl;
	std::cout << B_B"_____________________________________________" << RESET << std::endl;
	while (i < number_of_contact)
	{
			std::cout << B_B"|" << RESET;
			std::stringstream tempo;
			tempo << (i + 1);
			print_data(tempo.str()); std::cout << B_B"|" << RESET;
			print_data(contact_list[i].get_first_name()); std::cout << B_B"|" << RESET;
			print_data(contact_list[i].get_last_name()); std::cout << B_B"|" << RESET;
			print_data(contact_list[i].get_nickname()); std::cout << B_B"|" << RESET << std::endl;
			std::cout << B_B"_____________________________________________" << RESET << std::endl;
			i++;
	}
	std::cout << std::endl << std::endl << B_M"Choose a contact to see his/her contact sheet" << RESET << std::endl;
	std::string str;
	str = get_user_input();
	if (str.size() == 0)
		return (1);
	int	check = std::atoi(str.c_str());
	while (check < 1 || check > number_of_contact)
	{
		std::cout << std::endl << B_R"Wrong Input, please select a valid contact" << RESET << std::endl;
		str = get_user_input();
		if (str.size() == 0)
			return (1);
		check = std::atoi(str.c_str());
	}
	contact_selected(check - 1);
	std::cout << std::endl;
	return (0);
}