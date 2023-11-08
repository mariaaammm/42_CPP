#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &copy) : std::stack<T>(copy){}
        MutantStack& operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator	     begin();
        iterator	     end();
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();
};

template <typename T>
MutantStack<T>::MutantStack()
{
    // std::cout << "Default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    // std::cout << "Destructor called" << std::endl;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & other)
{
    if (this != &other)
        this->c = other.c;
    return (*this);
    // std::cout << "Copy assignemnt operator constructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}
