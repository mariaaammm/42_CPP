#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        _type = other._type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete (brain);
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

//void Dog::setType(const std::string &type){_type = type;}
std::string Dog::getType() const {return (_type);}