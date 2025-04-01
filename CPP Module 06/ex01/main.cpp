#include "Serializer.hpp"

int main(void)
{
	Data *tmp = new Data();
	tmp->value = 36;
	if (tmp == NULL)
	{
		std::cout << "ERROR Pointer is NULL" << std::endl;
		return (0);
	}
	std::cout << B_G "Value = " B_Y << tmp->value << RESET << std::endl;
	uintptr_t raw = Serializer::serialize(tmp);
	std::cout << B_G "Value raw serialize = " B_Y << raw << RESET << std::endl;
	tmp = Serializer::deserialize(raw);
	std::cout << B_G "Value Data deserialize = " B_Y << tmp->value << RESET << std::endl;
	delete(tmp);
	return 0;
}