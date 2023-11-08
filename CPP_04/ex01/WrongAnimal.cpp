#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    _type = copy._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    this->_type = other._type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "I'm WrongAnimal" << std::endl;
}

//void    WrongAnimal::setType(const std::string &type) {_type = type;}
std::string WrongAnimal::getType() const {return (_type);}