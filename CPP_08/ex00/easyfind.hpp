#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator res = std::find(container.begin(), container.end(), value);
    if (res == container.end())
        throw std::runtime_error("Value not found in container");
    return (res);
}
