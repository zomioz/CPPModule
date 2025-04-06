#include "easyfind.hpp"

int main(void)
{
	std::vector<int> container1;
	std::cout << "Add values : 0, 1, 2, 3, 4 to vector" << std::endl;
	for (int x = 0; x < 5; x++)
		container1.push_back(x);
	try
	{
		std::cout << "Searching value : 3 in vector" << std::endl;
		::easyFind(container1, 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Searching value : 20 in vector" << std::endl;
		::easyFind(container1, 20);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::list<int> container2;
	std::cout << "Add values : 0, 1, 2, 3, 4 to list" << std::endl;
	for (int x = 0; x < 5; x++)
		container2.push_back(x);
	try
	{
		std::cout << "Searching value : 3 in list" << std::endl;
		::easyFind(container2, 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Searching value : 20 in list" << std::endl;
		::easyFind(container2, 20);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}