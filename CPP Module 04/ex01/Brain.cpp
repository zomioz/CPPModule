#include "Brain.hpp"

Brain::Brain()
{
	std::cout << B_G "Constructor of Brain has been called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << B_G "copy Constructor of Brain has been called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << B_R "Destructor of Brain has been called" << std::endl;
}

Brain	&Brain::operator=(const Brain &second)
{
	std::cout << B_G "Surchage operator ""="" of Brain has been called" RESET  << std::endl;
	this->setIdeas(second.getIdeas());
	return (*this);
}

void	Brain::setIdeas(std::string idea)
{
	if (idea.size() > 100)
	{
		std::cout << B_R "This animal can't think that much (ideas > 100), standard ideas (I want Food) are put in his brain" RESET << std::endl;
		*this->ideas = "I Want Food";
		return ;
	}
	*this->ideas = idea;
}

std::string	Brain::getIdeas() const
{
	return (*this->ideas);
}