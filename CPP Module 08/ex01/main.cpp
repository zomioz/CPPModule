#include "Span.hpp"

int main(void)
{
	Span container1(3);
	try
	{
		container1.addNumber(1);
		container1.addNumber(3);
		container1.addNumber(10);
		container1.print_storage();
		container1.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << B_Y << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		std::cout << B_M "LongestSpan in container1 is : " B_Y << container1.longestSpan() << RESET << std::endl;
		std::cout << B_M "ShortestSpan in container1 is : " B_Y << container1.shortestSpan() << RESET << std::endl;
		Span container2(3);
		container2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << B_Y << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		Span container(50000);
		container.addMultipleNumber(50000);
		std::cout << B_M "LongestSpan in container1 is : " B_Y << container.longestSpan() << RESET << std::endl;
		std::cout << B_M "ShortestSpan in container1 is : " B_Y << container.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << std::endl;

	
	try
	{
		Span container2(50);
		container2.addNumber(10);
		container2.addMultipleNumber(50);
	}
	catch (std::exception &e)
	{
		std::cout << B_Y << e.what() << RESET << std::endl;
	}
}