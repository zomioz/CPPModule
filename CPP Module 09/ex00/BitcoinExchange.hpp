#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>
#include <cstdlib>

# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define RESET "\x1B[0m"

bool ParsingArgKey(std::string Key, bool Option);
bool ParsingArgDate(std::string Date, bool Option);

class BitcoinExchange
{
    public :
        BitcoinExchange();
        ~BitcoinExchange();
        bool FileDatabase();
        void HandleMyData(char **argv);
        void FoundNearestValue(std::string Date, float Key);
    private :
        std::map<std::string, float> DataBase;
        BitcoinExchange &operator=(const BitcoinExchange &second);
        BitcoinExchange(const BitcoinExchange &copy);
};

#endif