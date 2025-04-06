
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << B_G "Default constructor of MutantStack has been called" RESET << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << B_R "Destructor of MutantStack has been called" RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy)
{
	std::cout << B_G "Copy constructor of MutantStack has been called" RESET << std::endl;
	*this = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &second)
{
	std::cout << B_G "Surcharge operator = of MutantStack has been called" RESET << std::endl;
	if (this != &second)
	{
		this->c = second.c;
	}
	return *this;
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}