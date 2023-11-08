#pragma once
#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &other);    
        ~Brain();
    private:
        std::string ideas[100];
};