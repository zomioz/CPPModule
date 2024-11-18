#include <iostream>

int main(int argc, char **argv) {

	if (argc == 1)
	{
    	std::cout << "*Inaudible & loud noise*\n";
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string str = argv[i];
		for (int j = 0; str[j]; j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
    return (0);
}