#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();        
        Dog(const Dog &copy);        
        Dog &operator=(const Dog &other);        
        virtual ~Dog();
        //void setType(const std::string &type);
        std::string getType() const;
        void makeSound() const;
    private:
        Brain* brain;
};