#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		int x = 4;
		Animal *_animal[x];

		for (int i = 0; i < x; i++)
		{
			if (i % 2 == 0)
				_animal[i] = new Cat();
			else
				_animal[i] = new Dog();
		}

		for (int i = 0; i < x; i++)
		{
			_animal[i]->makeSound();
			delete _animal[i];
		}
		return 0;
	}
	// {
	// 	//TEST TO SHOW ANIMALS IDEAS
	// 	Dog _dog;
	// 	std::cout << std::endl << std::endl;
	// 	Cat	_cat;
	// 	std::cout << std::endl << std::endl;
	// 	std::cout << B_M "Dog Ideas : " << std::endl << B_Y "Creation of a temp dog to get his brain " B_Y << std::endl << (_dog.getBrain()).getIdeas() << RESET; std::cout << std::endl << std::endl;
	// 	std::cout << B_M "Cat Ideas : " << std::endl << B_Y "Creation of a temp cat to get his brain " B_Y << std::endl << (_cat.getBrain()).getIdeas() << RESET; std::cout << std::endl << std::endl;
	// 	return 0;
	// }
	// {
	// 	//TEST TO SHOW COPY ARE DEEP COPY
	// 	Dog _dog;
	// 	Dog _copy;
	// 	_copy = _dog;
	// 	return 0;
	// }
}