#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_Source[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &second);
		virtual void learnMateria(AMateria *mat);
		virtual AMateria* createMateria(std::string const & type);

};

#endif