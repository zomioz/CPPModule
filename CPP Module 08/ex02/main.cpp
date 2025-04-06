
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(4);
	std::cout << B_M "On top of my stack there is : " B_Y << mstack.top() << RESET << std::endl << std::endl;

	mstack.pop();
	std::cout << B_M "Size of my stack = " B_Y << mstack.size() << RESET << std::endl << std::endl;

	mstack.push(4);
	mstack.push(3);
	mstack.push(2);
	mstack.push(1);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << B_G "Display all my stack :" RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}