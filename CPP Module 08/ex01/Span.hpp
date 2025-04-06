#ifndef SPAN_HPP
#define SPAN_HPP

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <list>
#include <time.h>

class Span
{
	public :
		Span(unsigned int n);
		Span(const Span &copy);
		const Span &operator=(const Span &second);
		~Span();
		void addNumber(int add);
		void addMultipleNumber(unsigned int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int get_max() const;
		void print_storage() const;
	private :
		Span();
		unsigned int max;
		std::vector<int> storage;
};

#endif