#include "ScalarConverter.hpp"

int    ScalarConverter::_i;
float  ScalarConverter::_f;
double ScalarConverter::_d;
char   ScalarConverter::_c;
double ScalarConverter::_arg;

std::string ScalarConverter::_charMessage;
std::string ScalarConverter::_intMessage;
std::string ScalarConverter::_floatMessage;
std::string ScalarConverter::_doubleMessage;

int ScalarConverter::checkArg(const std::string &s)
{
    if (s.empty())
        return (1);
    if (s.compare("nan") == 0 || s.compare("nanf") == 0)
    {
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: nanf" << std::endl; 
        std::cout << "double: nan" << std::endl;
        return (1);
    }
    else if (s.compare("+inf") == 0 || s.compare("+inff") == 0)
    {
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: +inff" << std::endl; 
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    else if (s.compare("-inf") == 0 || s.compare("-inff") == 0)
    {
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: -inff" << std::endl; 
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    return (0);
}

type ScalarConverter::detectType(const std::string &s)
{
    char* end;
    _arg = strtod(s.c_str(), &end);
    if (s.length() == 1 && isprint((int)s[0]) && !isdigit((int)s[0]))
    {
        return (_CHAR);
    }
    if (!s.empty() && (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
    { 
        if (s.find('.') != std::string::npos && s[s.length() - 1] == 'f')
        {
            return (_FLOAT);
        }
        if (s.find('.') != std::string::npos)
        {
            return (_DOUBLE);
        }
        else
        {
            return (_INT);
        }
    }
    return (_UNDEFINED);
}

void ScalarConverter::convertChar(const std::string& arg)
{
    _c = arg[0];
    _i = static_cast<int>(_c);
    _f = static_cast<float>(_c);
    _d = static_cast<double>(_c);

    return ;
}

void ScalarConverter::convertInt(const std::string& arg)
{
    char* end;
    _arg = strtod(arg.c_str(), &end);

    if (_arg > std::numeric_limits<int>::max() || _arg < std::numeric_limits<int>::min())
    {
        _intMessage = "impossible";
    }
    _i = static_cast<int>(_arg);

    if ((_i < std::numeric_limits<char>::min()) || (_i > std::numeric_limits<char>::max()))
        _charMessage = "impossible";
    else if (isprint(_i))
        _c = static_cast<char>(_arg);
    else
        _charMessage = "Non displayable";

    _f = static_cast<float>(_arg);
    _d = static_cast<double>(_arg);
}

void    ScalarConverter::convertFloat(const std::string &arg)
{

    char *end;

    if (arg.find('.') != arg.rfind('.') && *(arg.end() - 1) == 'f')
    {
        return ;
    }
    _arg = strtod(arg.c_str(), &end);

    _f = static_cast<float>(_arg);
    if ((static_cast<int>(_f) < std::numeric_limits<char>::min())
         || (static_cast<int>(_f) > std::numeric_limits<char>::max()))
        _charMessage = "impossible";
    else if (!isprint(static_cast<int>(_f)))
        _charMessage = "Non displayable";
    else
        _c = static_cast<char>(_arg);
    if (_f != _f || _f > std::numeric_limits<int>::max() || _f < std::numeric_limits<int>::min())
        _floatMessage = "impossible";
    if (_f > std::numeric_limits<int>::max() || _f < std::numeric_limits<int>::min())
        _intMessage = "impossible";
    else
        _i = static_cast<int>(_arg);
    _d = static_cast<double>(_arg);
        
    return ;
}

void ScalarConverter::convertDouble(const std::string &arg)
{
    char *end;
    if (arg.empty())
    {
        return ;
    }
    _arg = strtod(arg.c_str(), &end);

    _d = static_cast<double>(_arg);
    if (_d != _d || _d > std::numeric_limits<double>::max() || _d < std::numeric_limits<double>::min())
        _doubleMessage = "impossible";
    if (arg.find('.') != std::string::npos)
    {
        if ((static_cast<double>(_d) < std::numeric_limits<char>::min())
            || (static_cast<double>(_d) > std::numeric_limits<char>::max()))
            _charMessage = "impossible";
        else if (isprint(static_cast<int>(_d)) == false)
            _charMessage = "Non displayable";
        else
            _c = static_cast<char>(_arg);
        if (_d > std::numeric_limits<int>::max() || _d < std::numeric_limits<int>::min())
            _intMessage = "impossible";
        else
            _i = static_cast<int>(_arg);
        _f = static_cast<float>(_arg);
    }
    return ;
}



void    ScalarConverter::convert(const std::string &s)
{
    if (s.empty())
        return ;
    if (checkArg(s))
        return ;
    switch(detectType(s))
    {
        case _CHAR:
            convertChar(s);
            break;
        case _INT:
            convertInt(s);
            break;
        case _FLOAT:
            convertFloat(s);
            break;
        case _DOUBLE:
            convertDouble(s);
            break;
        case _UNDEFINED:
            std::cout << "Enter valid argument" << std::endl;
            return ;
    }
    printResults();
}

void ScalarConverter::printResults()
{
    double ptr;


    std::cout << "char: ";
    if (_charMessage.empty())
        std::cout << "'" << _c << "'" << std::endl;
    else
        std::cout << _charMessage << std::endl;

    std::cout << "int: ";
    if (_intMessage.empty())
        std::cout << _i << std::endl;
    else
        std::cout << _intMessage << std::endl;

    std::cout << "float: ";
    if (_f > std::numeric_limits<float>::max() || _f < std::numeric_limits<float>::min())
        std::cout << _f << 'f' << std::endl;
    else if (_floatMessage.empty())
    {
        std::cout << _f;
        if (modf(_f, &ptr) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    else
        std::cout << _floatMessage << std::endl;

    std::cout << "double: ";
    if (_d > std::numeric_limits<double>::max() || _d < std::numeric_limits<double>::min())
        std::cout << _d << std::endl;
    else if (_doubleMessage.empty())
    {
        std::cout << _d;
        if (modf(_d, &ptr) == 0)
            std::cout << ".0" << std::endl;;
    }
    else
        std::cout << _doubleMessage << std::endl;

    return ;
}
