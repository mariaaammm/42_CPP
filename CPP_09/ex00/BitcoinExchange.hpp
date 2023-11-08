#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void fillData();
        void readInput(char *iFile);


    private:
        std::map<std::string, double, std::greater<std::string> >  _dataBase;

        void parseInput(const std::string &s);
        void parseData(const std::string &s);
        bool validValue(const std::string &s);
        bool validDate(const std::string &year, const std::string &month, const std::string &day);
        bool handleDate(const std::string &s);
        bool checkDigits(const std::string &s);
        double strTod(std::string s);
        bool	dateErrors(const std::string& date);
};

