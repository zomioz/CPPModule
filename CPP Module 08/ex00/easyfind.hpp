#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void easyFind(T container, int n)
{
	typename T::iterator found = std::find(container.begin(), container.end(), n);
	if (found != container.end())
	{
		std::cout << "Value found : " << *found << std::endl;
		return ;
	}
	throw(std::runtime_error("Error : No occurence found"));
}

#endif