#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    _type = copy._type;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    this->_type = other._type;
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

//void    AAnimal::setType(const std::string &type) {_type = type;}
std::string AAnimal::getType() const {return (_type);}