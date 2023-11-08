#pragma once 
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

enum type
{
    _CHAR = 1,
    _INT = 2,
    _FLOAT = 3,
    _DOUBLE = 4,
    _UNDEFINED = 0
};

class ScalarConverter
{
        public:
                static void convert(const std::string& s);

        private:
                ScalarConverter();
                ScalarConverter(const ScalarConverter& copy);
                ScalarConverter& operator=(const ScalarConverter& other);
                ~ScalarConverter();

                static double _arg;
                static char _c;
                static int _i;
                static float _f;
                static double _d;
                
                static std::string _generalMessage;
                static std::string _charMessage;
                static std::string _intMessage;
                static std::string _floatMessage;
                static std::string _doubleMessage;

                static void convertChar(const std::string& arg);
                static void convertInt(const std::string& arg);
                static void convertFloat(const std::string& arg);
                static void convertDouble(const std::string& arg);
                static void printResults();
                static int checkArg(const std::string& s);
                static type detectType(const std::string &s);
};