#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        _type = other._type;
     std::cout << "WrongCat copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meow" << std::endl;
}

void WrongCat::setType(const std::string &type){_type = type;}
std::string WrongCat::getType() const {return (_type);}