#include "Array.hpp"

int main(void)
{
	Array<int> fill_int(5);
	for (int x = 0; x < 5; x++)
	{
		fill_int[x] = 10 + x;
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int[" << B_Y << x << B_M "] : " B_Y << fill_int[x] << RESET << std::endl;
	}
	Array<std::string> fill_string(5);
	for (int x = 0; x < 5; x++)
	{
		fill_string[x] = "Hello";
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int[" << B_Y << x << B_M "] : " B_Y << fill_string[x] << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;

	Array<int> fill_int_second;
	fill_int_second = fill_int;
	for (int x = 0; x < 5; x++)
	{
		fill_int[x] = 20 + x;
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int[" << B_Y << x << B_M "] : " B_Y << fill_int[x] << RESET << std::endl;
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int_second[" << B_Y << x << B_M "] : " B_Y << fill_int_second[x] << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;

	Array<int> fill_int_third(fill_int);
	for (int x = 0; x < 5; x++)
	{
		fill_int[x] = 30 + x;
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int[" << B_Y << x << B_M "] : " B_Y << fill_int[x] << RESET << std::endl;
	}
	for (int x = 0; x < 5; x++)
	{
		std::cout << B_M "fill_int_third[" << B_Y << x << B_M "] : " B_Y << fill_int_third[x] << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;
	
	try 
	{
		Array<int> test(99999);
	}
	catch (std::exception &e)
	{
		std::cout << B_R "Exception catch : " B_Y << e.what() << RESET << std::endl;
	}
	try 
	{
		fill_int[-1] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << B_R "Exception catch : " B_Y << e.what() << RESET << std::endl;
	}
	try 
	{
		fill_int[56] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << B_R "Exception catch : " B_Y << e.what() << RESET << std::endl;
	}
	return 0;
}