#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	public :
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat	&operator=(const Cat &second);
		Brain	getBrain() const;
		virtual void	makeSound();
	private :
		Brain *_Brain;
};

#endif