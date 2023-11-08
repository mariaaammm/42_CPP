#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();        
        Cat(const Cat &copy);        
        Cat &operator=(const Cat &other);        
        virtual ~Cat();
        void makeSound() const;
        //void setType(const std::string &type);
        std::string getType() const;
    private:
        Brain* brain;
};