#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
        _type = other._type;
     std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

void Dog::setType(const std::string &type){_type = type;}
std::string Dog::getType() const {return (_type);}