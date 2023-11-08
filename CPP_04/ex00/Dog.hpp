#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();        
        Dog(const Dog &copy);        
        Dog &operator=(const Dog &other);        
        virtual ~Dog();
        void setType(const std::string &type);
        std::string getType() const;
        void makeSound() const;
};