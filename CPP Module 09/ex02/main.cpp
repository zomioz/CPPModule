#include "PmergeMe.hpp"

bool ParsingArg(char **argv, int argc)
{
    for (int x = 1; x < argc; x++)
    {
        std::string str(argv[x]);
        if (str.empty())
            return std::cerr << B_R "Error : Empty argument detected" RESET << std::endl, false;
        size_t check = str.find_first_not_of("0123456789", 0);
        if (check != std::string::npos)
            return std::cerr << B_R "Error : non numeric argument detected" RESET << std::endl, false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return std::cerr << B_R "Error : not enough arguments" RESET << std::endl, 1;
    if (!ParsingArg(argv, argc))
        return 1;

    PmergeMe test;
    test.FillVector(argv, argc);
    test.PrintContainerVector();
    std::string time_vector = test.MeasureCreatePairVector(test.getContainerVector());
    test.PrintContainerVectorSorted();


    test.FillDeque(argv, argc);
    test.PrintContainerDeque();
    std::string time_deque = test.MeasureCreatePairDeque(test.getContainerDeque());
    test.PrintContainerDequeSorted();
    std::cout << time_vector << std::endl;
    std::cout << time_deque << std::endl;
}