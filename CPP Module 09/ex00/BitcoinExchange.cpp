#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    DataBase = copy.DataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &second)
{
    if (this != &second)
        *this = second;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::HandleMyData(char **argv)
{
    std::ifstream InFile;
    InFile.open(argv[1], std::ifstream::in);

    std::string str;
    std::getline(InFile, str);
    std::string ex = "date | value";
    if (str != ex)
    {
        std::cerr << B_R "1st line of input file should be \"date | value\" and all lines should be prototype like this" RESET << std::endl;
        return ;
    }

    std::string Date;
    float      Key;

    while (std::getline(InFile, str))
    {
        size_t pos = str.find("|");
        if (pos == std::string::npos)
        {
            std::cerr << B_R "MyData error line : " << str << RESET << std::endl;
            continue ;
        }
        if (pos != 11)
        {
            std::cerr << B_R "MyData error line : " << str << RESET << std::endl;
            continue ;
        }
        Date = str.substr(0, pos - 1);
        if (!ParsingArgDate(Date, true))
        {
            std::cerr << B_R "MyData error with Date line : " << str << RESET << std::endl;
            continue ;
        }
        std::string Key_str = str.substr(pos + 2);
        if (!ParsingArgKey(Key_str, true))
        {
            std::cerr << B_R "MyData error with Value line : " << str << RESET << std::endl;
            continue ;
        }
        Key = std::strtof((str.substr(pos + 1)).c_str(), NULL);

        FoundNearestValue(Date, Key);
    }
}

bool BitcoinExchange::FileDatabase()
{
    std::ifstream InFile;
    InFile.open("data.csv", std::ifstream::in);

    std::string str;
    std::getline(InFile, str);
    std::string ex = "date,exchange_rate";
    if (str != ex)
        return std::cerr << B_R "1st line of data.csv file should be \"date,exchange_rate\" and all lines should be prototype like this" RESET << std::endl, false;

    std::string Date;
    float      Key;

    while (std::getline(InFile, str))
    {
        int pos = str.find(",");
        if (pos != 10)
            return std::cerr << B_R "DataBase error line : " << str << RESET << std::endl, false;

        Date = str.substr(0, pos);
        if (!ParsingArgDate(Date, false))
            return std::cerr << B_R "DataBase error with Date line : " << str << RESET << std::endl, false;

        std::string Key_str = str.substr(pos + 1);
        if (!ParsingArgKey(Key_str, false))
            return std::cerr << B_R "DataBase error with Value line : " << str << RESET << std::endl, false;
        Key = std::strtof((str.substr(pos + 1)).c_str(), NULL);

        DataBase[Date] = Key;
    }
    return true;
}


void BitcoinExchange::FoundNearestValue(std::string Date, float Key)
{
    std::map<std::string, float>::iterator it = DataBase.begin();

    while(it != DataBase.end())
    {
        if (it->first == Date)
        {
            std::cout << B_M "At " B_Y << Date << B_M " You got " B_Y << Key << B_M " Bitcoin at the  " B_Y << Date << B_M " It's worth : " B_Y << Key * it->second << RESET << std::endl;
            return ;
        }
        it++;
    }

    std::map<std::string, float>::iterator lower = DataBase.lower_bound(Date);
    if (lower == DataBase.end())
    {
        lower--;
        std::cout << B_M "At " B_Y << Date << B_M " You got " B_Y << Key << B_M " Bitcoin at the nearest date, " B_Y << lower->first << B_M " It's worth : " B_Y << Key * lower->second << RESET << std::endl;
        return ;
    }
    if (lower != DataBase.begin())
    {
        std::map<std::string, float>::iterator prev = --lower;
        if (Date > lower->first && Date > prev->first)
            lower = prev;
    }
    std::cout << B_M "At " B_Y << Date << B_M " You got " B_Y << Key << B_M " Bitcoin at the nearest date, " B_Y << lower->first << B_M " It's worth : " B_Y << Key * lower->second << RESET << std::endl;
    return ;

}
