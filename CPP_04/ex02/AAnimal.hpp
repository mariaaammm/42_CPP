#pragma once
#include <iostream>

class AAnimal
{
    public:
        AAnimal();        
        AAnimal(const AAnimal &copy);        
        AAnimal &operator=(const AAnimal &other);        
        virtual ~AAnimal();
        virtual void    makeSound() const = 0;
        //void setType(const std::string &type);
        std::string getType() const;
    protected:
        std::string _type;
};

