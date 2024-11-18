#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public :
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat	&operator=(const Cat &second);
		Brain	getBrain() const;
	private :
		Brain *_Brain;
};

#endif