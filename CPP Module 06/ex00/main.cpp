#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return (1);
    }
    std::string value = argv[1];
    ScalarConverter::convert(value);
    return (0);
}