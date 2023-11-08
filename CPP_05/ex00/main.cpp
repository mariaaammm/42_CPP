#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat b("Bob", 149);
        for (int i = 0; i < 5; ++i)
        {
            b.decrease();
            std::cout << b << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

// int main()
// {
//     try
//     {
//         {
//             Bureaucrat b("Bob", 3);
//             std::cout << b << std::endl;
//             b.increase();
//             std::cout << b << std::endl;
//         }
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return (0);
// }