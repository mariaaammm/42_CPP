#pragma once
#include <iostream>

class Animal
{
    public:
        Animal();        
        Animal(const Animal &copy);        
        Animal &operator=(const Animal &other);        
        virtual ~Animal();
        virtual void    makeSound() const;
        //virtual void setType(const std::string &type);
        std::string getType() const;
    protected:
        std::string _type;
};

