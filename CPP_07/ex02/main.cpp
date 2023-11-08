#include "Array.hpp"

int main()
{
    Array<int> arr(5);
    std::cout <<"Size of array ->   "<< arr.size() <<std::endl;
    try
    {
        for (unsigned int i = 0; i < arr.size(); ++i)
        {
            arr[i] = i;
            std::cout << arr[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Array<std::string> s(5);
    try
    {
        for (unsigned int i = 0; i < s.size(); ++i)
        {
            s[0] = "Hello";
            s[1] = "Nice";
            s[2] = "to";
            s[3] = "you";
            s[4] = ":)";
            std::cout << s[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        arr[-1] = 11;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0); 
}