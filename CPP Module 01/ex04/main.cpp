#include <iostream>
#include <fstream>

# define B_R   "\x1B[1;31m"
# define RESET "\x1B[0m"

int	replace_string(std::string str, std::string s1, std::string s2, const std::string infile)
{
	int check;
	int	i = 0;
	std::ofstream outfile;
	std::string end = ".replace";
	outfile.open((infile + end).c_str(), std::ofstream::out);
	if (outfile.fail())
		return (1);
	while (i < (int)str.size())
	{
		check = str.find(s1, i);
		if (check == -1)
		{
			outfile << str[i];
			i++;
		}
		else
		{
			int	j = i;
			while (check - j)
			{
				outfile << str[i];
				check--;
				i++;
			}
			outfile << s2;
			i += s1.size();
		}
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 4)
	{
		std::cout << B_R << "Please enter valid input : (filename, string one, string two)" << RESET << std::endl;
		return (1);
	}
	std::ifstream	infile;
	std::string		str;
	char			c;
	infile.open(argv[1], std::ifstream::in);
	if (infile.fail())
	{
		std::cout << B_R "Error during infile.open()" RESET << std::endl; 
		return (1);
	}
	while (infile.get(c))
		str += c;
	if (replace_string(str, argv[2], argv[3], argv[1]) == 1)
		std::cout << B_R "Error during outfile.open()" << RESET << std::endl;
	infile.close();
	return (0);
}