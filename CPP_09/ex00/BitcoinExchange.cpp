#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {*this = copy;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _dataBase = other._dataBase;
    return (*this);
}

double BitcoinExchange::strTod(std::string s)
{
    char *end;
    double res = strtod(s.c_str(), &end);

    if (*end)
        return (0);
    return (res);
}

void BitcoinExchange::parseData(const std::string &s)
{
    std::string key;
    std::string value;
    int i;

    i = s.find(',');
    key = s.substr(0, i);
    value = s.substr(i + 1, (s.size() - key.size()));
    _dataBase.insert(std::make_pair(key, strTod(value)));
}

void BitcoinExchange::fillData()
{
    std::ifstream dataFile("data.csv");
    std::string data;

    getline(dataFile, data);
    while (!dataFile.eof())
    {
        getline(dataFile, data);
        if (data.empty())
            break;
        parseData(data); 
    }
}

/******************************************************************/

void BitcoinExchange::parseInput(const std::string &s)
{
    size_t i;
    double res;
    double val;
    std::string date;
    std::string valStr;

    i = s.find('|');
    date = s.substr(0, i - 1);
    valStr = s.substr(i + 1, s.size() - _dataBase.size());
    val = strTod(valStr);
    if (i == std::string::npos)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }
    if (validValue(valStr) == 0 || handleDate(date) == 0)
        return ;
    std::map<std::string, double>::const_iterator iter = _dataBase.lower_bound(date);
    if (iter == _dataBase.end()) {
        std::cout << date  << " => not found"<< std::endl;
        return ;
    }
    res = iter->second * val;

    std::cout << date << " "  << "=> " << val <<  " = " << res << std::endl;
}

void BitcoinExchange::readInput(char *iFile)
{
    std::ifstream inputFile(iFile);
    std::string data;

    getline(inputFile, data);
    //while (!inputFile.eof())
    while (getline(inputFile, data))
    {
        // getline(inputFile, data);
        if (data.empty())
            continue ;
        parseInput(data); 
    }
}

bool BitcoinExchange::validValue(const std::string &val)
{
    double value;
    char   *end;
    
    value = strtod(val.c_str(), &end);
    if (*end != '\0')
    {
        std::cout<<"Error: invalid value"<<std::endl;
        return false;
    }
    else
    {

        if (value > 1000)
        {
            std::cout << "Error: too large a number" << std::endl;
            return (false);
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number" << std::endl;
            return (false);
        }
    }
    return (true);
}

enum Month
{
    _JANUARY = 1,
    _FEBRUARY = 2,
    _MARCH = 3,
    _APRIL = 4,
    _MAY = 5,
    _JUNE = 6,
    _JULY = 7,
    _AUGUST = 8,
    _SEPTEMBER = 9,
    _OCTOBER = 10,
    _NOVEMBER = 11,
    _DECEMBER = 12
};

bool BitcoinExchange::checkDigits(const std::string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]) == 0)
            return (false);
    }
    return (true);
}

bool BitcoinExchange::validDate(const std::string &year, const std::string &month, const std::string &day)
{
    if (checkDigits(year) == 0 || checkDigits(month) == 0 || checkDigits(day) == 0)
    {
        return (false);
    }
    int yearDigit = atoi(year.c_str());
    int monthDigit = atoi(month.c_str());
    int numberOfDays = atoi(day.c_str());

    if (monthDigit == 2)
    {
        if (yearDigit % 4 == 0 && (yearDigit % 100 != 0 || yearDigit % 400 == 0))
        {
            if (numberOfDays > 29)
                return (false);
        }
        else
        {
            if (numberOfDays > 28)
                return (false);
        }
    }
    else if (monthDigit == 1 || monthDigit == 3 || monthDigit == 5 || monthDigit == 7 \
        || monthDigit == 8 || monthDigit == 10 || monthDigit == 12)
        {
            if (numberOfDays > 31)
                return (false);
        }
    else if (monthDigit == 4 || monthDigit == 6 || monthDigit == 9 || monthDigit == 11)
    {
        if (numberOfDays > 30)
            return (false);
    }
    else if (monthDigit > 12)
        return (false);
    return (true);
}

bool BitcoinExchange::handleDate(const std::string &s)
{
    std::string year;
    std::string month;
    std::string day;
    size_t posYear;
    size_t posMonth;

    posYear = s.find('-');
    year = s.substr(0, posYear);
    posMonth = s.find('-', posYear + 1);

    if (posMonth - posYear == 1) {
        throw std::invalid_argument("Error: invalid argument");
    }
    month = s.substr(posYear + 1, posMonth - posYear - 1);
    day = s.substr(posMonth + 1, s.length() -  posMonth);

    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
    {
        std::cerr << "Error: bad input => " << s << std::endl;
        return (false);
    }

    if (validDate(year, month, day) == 0)
    {
        std::cerr << "Error: bad input => " << s << std::endl;
        return (false);
    }

    return (true);
}


