#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << B_G "Constructor of Serializer called" RESET << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << B_G "Copy Constructor of Serializer called" RESET << std::endl;
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &second)
{
	std::cout << B_G "Surcharge operator ""="" of Serializer called" RESET << std::endl;
	(void)second;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << B_R "Destructor of Serializer called" RESET << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
		return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}