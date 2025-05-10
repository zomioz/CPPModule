#include "RPN.hpp"

bool IsOperator(char c)
{
    if (c != '+' && c != '-' && c != '/' && c!= '*')
        return false;
    return true;
}

bool ParsingArg(char ** argv)
{
    std::string str(argv[1]);
    int operators = 0;
    int numbers = 0;

    for (size_t x = 0; x < str.length(); x++)
    {
        if (!((str[x] >= '0' && str[x] <= '9') || IsOperator(str[x]) || str[x] == ' '))
            return false;
        if (((str[x] >= '0' && str[x] <= '9') || IsOperator(str[x])) && x > 0 && str[x - 1] != ' ')
            return false;
        if (str[x] >= '0' && str[x] <= '9')
            numbers++;
        if (IsOperator(str[x]))
            operators++;
    }
    if ((numbers - 1) != operators)
        return false;
    return true;
}

bool CheckerOrder(char **argv)
{
    std::string str(argv[1]);
    int numbers = 0;
    
    for (size_t x = 0; (x < str.length() && !IsOperator(str[x]) && (str[x] == ' ' || isdigit(str[x]))); x++)
    {
        if (isdigit(str[x]))
            numbers++;
    }
    if (numbers < 2)
        return false;
    return true;
}

bool CheckerSequence(char **argv)
{
    std::string str(argv[1]);
    int operators = 0;
    int numbers = 0;
    bool first = true;
    size_t x = 0;

    while (x < str.length())
    {
        while (x < str.length() && (str[x] == ' ' || isdigit(str[x])))
        {
            if (isdigit(str[x]))
                numbers++;
            x++;
        }
        while (x < str.length() && (str[x] == ' ' || IsOperator(str[x])))
        {
            if (IsOperator(str[x]))
                operators++;
            x++;
        }
        if (first == true && numbers != (operators + 1))
            return false;
        if (first == false && numbers != operators)
            return false;
        numbers = 0;
        operators = 0;
        first = false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return std::cerr << B_R "Error : not enough or too many Parameters" RESET << std::endl, 1;
    if (!ParsingArg(argv))
        return std::cerr << B_R "Error : Bad Parameters" RESET << std::endl, 1;
    if (!CheckerOrder(argv))
        return std::cerr << B_R "Error : Bad order, thanks to start by number" RESET << std::endl, 1;
    if (!CheckerSequence(argv))
        return std::cerr << B_R "Error : Bad order during sequence" RESET << std::endl, 1;
    Rpn tmp;
    tmp.HandleArg(argv);
    return 0;
}