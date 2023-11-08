#include "Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
//    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    this->_type = copy._type;
//    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->_type = other._type;
//    std::cout << "Ice copy assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
//    std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const
{
    return (new Ice(*this));
}

 void    Ice::use(ICharacter& target)
 {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
 }