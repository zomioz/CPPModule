#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

struct Data
{
	int value;
};

class Serializer
{
	public :
		static uintptr_t serialize(Data *ptr);
		static Data * deserialize(uintptr_t raw);
	private :
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &second);
};

#endif