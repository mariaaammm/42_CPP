#include "easyfind.hpp"

int main()
{
    int arr[] = {9, 3, 7, 8, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    try
    {
        std::vector<int>::iterator iter = easyfind(vec, 3);
        std::cout << "Value found at index: " << std::distance(vec.begin(), iter) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}

