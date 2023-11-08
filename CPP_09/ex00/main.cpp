#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cerr << "2 arguments are required!" << std::endl;
            return (-1);
        }
        else
        {
            BitcoinExchange btc;
            btc.fillData();
            btc.readInput(av[1]);
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}


