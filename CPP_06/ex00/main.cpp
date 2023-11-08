#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "ERROR: Count arguments" << std::endl;
        return (0);
    }
    else
    {
        std::string arg = argv[1];
        ScalarConverter::convert(arg);
    }
    return (0);
}