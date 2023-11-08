#include "Cure.hpp"

Cure::Cure()
{
    this->_type = "cure";
//    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    this->_type = copy._type;
//   std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->_type = other._type;
//    std::cout << "Cure copy assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
//    std::cout << "Cure destructor called" << std::endl;
}

Cure *Cure::clone() const
{
    return (new Cure(*this));
}

 void    Cure::use(ICharacter& target)
 {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
 }