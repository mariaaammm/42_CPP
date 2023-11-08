#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    _type = copy._type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    this->_type = other._type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal make sound" << std::endl;
}

void    Animal::setType(const std::string &type) {_type = type;}
std::string Animal::getType() const {return (_type);}