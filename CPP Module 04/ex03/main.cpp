#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

# define JUMP std::cout << std::endl
# define LEARN std::cout << B_M "learn new Materia :" RESET << std::endl
# define B_LEARN std::cout << B_M "Can't learn new Materia :" RESET << std::endl
# define EQUIP std::cout << B_M "new Materia equiped :" RESET << std::endl
# define B_EQUIP std::cout << B_M "Can't equiped new Materia :" RESET << std::endl

int	main(void)
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		return 0;
	}
	// {
	// 	std::cout << B_M "Creating a Ice IMateriaSource" RESET << std::endl;
	// 	IMateriaSource *ice_source = new MateriaSource(); JUMP; LEARN;
	// 	ice_source->learnMateria(new Ice());LEARN;
	// 	ice_source->learnMateria(new Ice());LEARN;
	// 	ice_source->learnMateria(new Ice());LEARN;
	// 	ice_source->learnMateria(new Ice()); JUMP; B_LEARN;

	// 	AMateria *ice = new Ice();
	// 	ice_source->learnMateria(ice);
	// 	delete ice, JUMP; JUMP;

	// 	std::cout << B_M "Creating a Ice & Cure IMateriaSource" RESET << std::endl;
	// 	IMateriaSource *source = new MateriaSource();
	// 	source->learnMateria(new Ice());
	// 	source->learnMateria(new Cure()); JUMP; JUMP;

	// 	std::cout << B_M "Creating my charaters" RESET << std::endl;
	// 	ICharacter *bob = new Character("bob");
	// 	ICharacter *daniel = new Character("daniel");JUMP;JUMP;

	// 	std::cout << B_M "Attribute Materia to my characters" RESET << std::endl;
	// 	bob->equip(source->createMateria("ice"));EQUIP;
	// 	bob->equip(source->createMateria("cure"));EQUIP;
	// 	bob->equip(ice);EQUIP;
	// 	bob->equip(source->createMateria("cure"));JUMP;B_EQUIP;
	// 	bob->equip(ice);JUMP;JUMP;

	// 	std::cout << B_M "Bob use Materia on daniel" RESET << std::endl;
	// 	bob->use(0, *daniel);
	// 	bob->use(1, *daniel);
	// 	bob->use(-1, *daniel);JUMP; JUMP;

	// 	std::cout << B_M "Bob unequiped Materia" RESET << std::endl;
	// 	bob->unequip(2);JUMP;JUMP;
		
	// 	std::cout << B_M "Deleting My characters and Materia from they Inventorys" RESET << std::endl;
	// 	delete bob;JUMP;
	// 	delete daniel;JUMP;JUMP;

	// 	std::cout << B_M "Deleting My MateriaSources and they Inventorys" RESET << std::endl;
	// 	delete ice_source;JUMP;
	// 	delete source;JUMP;JUMP;
	// 	return 0;
	// }
}