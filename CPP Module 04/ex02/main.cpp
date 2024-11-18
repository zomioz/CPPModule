#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		int x = 4;
		AAnimal *_Aanimal[x];

		for (int i = 0; i < x; i++)
		{
			if (i % 2 == 0)
				_Aanimal[i] = new Cat();
			else
				_Aanimal[i] = new Dog();
		}

		for (int i = 0; i < x; i++)
		{
			_Aanimal[i]->makeSound();
			delete _Aanimal[i];
		}
		return 0;
	}
	// {
	// 	Dog _dog;
	// 	std::cout << std::endl << std::endl;
	// 	Cat	_cat;
	// 	std::cout << std::endl << std::endl;
	// 	std::cout << B_M "Dog Ideas : " << std::endl << B_Y "Creation of a temp dog to get his brain " B_Y << std::endl << (_dog.getBrain()).getIdeas() << RESET; std::cout  << std::endl << std::endl;
	// 	std::cout << B_M "Cat Ideas : " << B_Y "Creation of a temp cat to get his brain " B_Y << std::endl << (_cat.getBrain()).getIdeas() << RESET; std::cout  << std::endl << std :: endl;
	// 	return 0;
	// }
	// {
	// 	Dog _dog;
	// 	Dog _copy;
	// 	_copy = _dog;
	// 	return 0;
	// }
}