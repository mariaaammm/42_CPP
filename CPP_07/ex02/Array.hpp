#pragma once
#include <iostream>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &other);
        ~Array();

        T &operator[](unsigned int i);
        unsigned int size();

        class OutOfBoundsException : public std::exception
		{
			const char	*what() const throw();
		};	

    private:
        unsigned int _n;
        T*           _elements;
};

template <typename T>
Array<T>::Array()
{
    _n = 0;
    _elements = NULL;
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _n = n;
    _elements = new T[n];
    std::cout << "Parameter constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    _n = copy._n;
    _elements = new T[copy._n];
    for (unsigned int i = 0; i < _n; ++i)
        _elements[i] = copy._elements[i];
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _elements;
        _n = other._n;
        _elements = new T(other._n);
        for (unsigned int i = 0; i < _n; ++i)
            _elements[i] = other._elements[i];
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _elements;
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _n)
        throw OutOfBoundsException();
    return (_elements[i]);
}

template <typename T>
unsigned int Array<T>::size(){return (_n);}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Thrown out of bounds exception");
}