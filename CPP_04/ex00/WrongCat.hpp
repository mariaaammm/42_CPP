#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();        
        WrongCat(const WrongCat &copy);        
        WrongCat &operator=(const WrongCat &other);        
        virtual ~WrongCat();
        // void makeSound() const;
        void setType(const std::string &type);
        std::string getType() const;
};
