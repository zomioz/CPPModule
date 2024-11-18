#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	public :
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog	&operator=(const Dog &second);
		Brain	getBrain() const;
		virtual void	makeSound();
	private :
		Brain *_Brain;
};

#endif