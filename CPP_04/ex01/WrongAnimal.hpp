#pragma once
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();        
        WrongAnimal(const WrongAnimal &copy);        
        WrongAnimal &operator=(const WrongAnimal &other);        
        virtual ~WrongAnimal();
        void    makeSound() const;
        //virtual void setType(const std::string &type);
        std::string getType() const;
    protected:
        std::string _type;
};