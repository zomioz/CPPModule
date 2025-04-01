#ifndef ARRAY_HPP
#define ARRAY_HPP

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

#include <iostream>

template <typename T>
class Array
{
	public :
		Array();
		Array(unsigned int n);
		Array(const Array &second);	
		Array<T> &operator=(const Array&copy);
		T &operator[](const unsigned int x);
		~Array();
		class OutOfBounds : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
		class ArrayTooBig : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
		unsigned int get_size() const;
	private :
		T *array;
		unsigned int size;
};

#include "Array.tpp"

#endif