#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
//    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    _type = copy._type;
//    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
    this->_type = other._type;
//    std::cout << "AMateria copy assignment operator called" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
//    std::cout << "Animal destructor called" << std::endl;
}

std::string const &AMateria::getType() const {return (_type);}
void AMateria::use(ICharacter& target){(void)target;}