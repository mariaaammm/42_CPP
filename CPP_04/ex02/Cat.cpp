#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
    //brain = new Brain(*copy.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        _type = other._type;
        //delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete (brain);
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

//void Cat::setType(const std::string &type){_type = type;}
std::string Cat::getType() const {return (_type);}