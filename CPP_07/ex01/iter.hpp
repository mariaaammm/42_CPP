#pragma once
#include <iostream>

template<typename T, typename U>

void iter(T *arr, size_t len, void(*printArr)( U&))
{
    for (size_t i = 0; i < len; ++i)
        printArr(arr[i]);
}


template<typename T>

void    printArr(T &a) {std::cout << a << " ";}