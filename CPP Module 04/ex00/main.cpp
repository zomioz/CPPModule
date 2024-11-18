#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << std::endl << "Test for WrongAnimal" << std::endl;

	const WrongAnimal* x = new WrongAnimal();
	const WrongAnimal* y = new WrongCat(); 

	std::cout << x->getType() << " " << std::endl;
	std::cout << y->getType() << " " << std::endl;

	x->makeSound();
	y->makeSound();

	delete meta;
	delete j;
	delete i;
	delete x;
	delete y;
	return 0;
}