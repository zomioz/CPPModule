#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

# include <iostream>
# include <stack>
# include <list>
# include <algorithm>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &copy);
		~MutantStack();
		MutantStack<T>&	operator=(const MutantStack<T> &second);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif