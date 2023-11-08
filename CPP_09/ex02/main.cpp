#include "PMergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
        {
            std::cerr << "Enter data" << std::endl;
            return (0);
        }
        PMergeMe data;
        if (data.isDigit(ac, av) == false)
            return (0);
        data.fillArgs(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
