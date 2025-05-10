#include "BitcoinExchange.hpp"

bool ParsingArgDate(std::string Date, bool Option)
{
    if (Date.substr(4, 1) != "-" || Date.substr(7, 1) != "-")
        return false;
    std::string Year = Date.substr(0, 4);
    std::string Month = Date.substr(5, 2);
    std::string Day = Date.substr(8, 2);
    std::string Array[] = {Year, Month, Day};
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t x = 0; x < Array[i].size(); x++)
        {
            if (!std::isdigit(Array[i][x]))
                return false;
        }
    }
    int ArrayInt[] = {std::atoi(Year.c_str()), std::atoi(Month.c_str()), std::atoi(Day.c_str())};
    for (size_t i = 0; i < 3; i++)
    {
        if (Option == false && i == 0 && (ArrayInt[i] < 2009 || ArrayInt[i] > 9999))
            return false;
        if (Option == true && i == 0 && (ArrayInt[i] < 2009 || ArrayInt[i + 2] < 2 || ArrayInt[i] > 2025))
            return false;
        if (i == 1 && (ArrayInt[i] < 0 || ArrayInt[i] > 12))
            return false;
        if (i == 2 && ((ArrayInt[i] < 1 || ArrayInt[i] > 31) || ((ArrayInt[1] == 4 || ArrayInt[1] == 6 || ArrayInt[1] == 9 || ArrayInt[1] == 11) && ArrayInt[i] > 30) || (ArrayInt[0] % 4 != 0 && ArrayInt[1] == 2 && ArrayInt[i] > 28) || (ArrayInt[0] % 4 == 0 && ArrayInt[1] == 2 && ArrayInt[i] > 29)))
            return false;
    }
    return true;
}

bool ParsingArgKey(std::string Key, bool Option)
{
    int count = 0;
    for (size_t x = 0; x < Key.length(); x++)
    {
        if (!std::isdigit(Key[x]) && Key[x] != '.')
            return false;
        if (Key[x] == '.')
            count++;
    }
    if (count > 1)
        return false;

    float value = std::strtof(Key.c_str(), NULL);
    if (Option == true && (value < 0 || value > 1000))
        return false;
    return true;
}

bool OpenAndCheck(char *file_char)
{
    std::ifstream InFile;
    std::ifstream DataBase;
    InFile.open(file_char, std::ifstream::in);
    if (!InFile.is_open())
        return false;
    DataBase.open("data.csv", std::ifstream::in);
    if (!DataBase.is_open())
        return false;
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return std::cerr << B_R "Not enough or too many Parameters, ./BitcoinExchange \"Data Base\"." RESET << std::endl, 1;
    if (!OpenAndCheck(argv[1]))
        return std::cerr << B_R "Error: can't open a file" RESET << std::endl, 1;

    BitcoinExchange All;
    if (!All.FileDatabase())
        return std::cerr << B_R "Error : Bad format in Data.csv" RESET << std::endl, 1;
    All.HandleMyData(argv);
}