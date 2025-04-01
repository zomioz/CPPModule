#include "iter.hpp"

int main(void)
{
	int array[] = {1,2,3,4,5};
	iter(array, 5, my_print<int>);
	std::cout << std::endl;
	iter(array, 5, incrementation<int>);
	iter(array, 5, my_print<int>);
	return 0;
}
/* {
	std::string words[5] = {"Hello", "Hello", "Hello", "Hello", "Hello"};
	iter(words, 5, my_print<std::string>);
	std::cout << std::endl;
	iter(words, 5, change_word<std::string>);
	iter(words, 5, my_print<std::string>);
	return 0;
} */