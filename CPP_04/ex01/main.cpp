#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    int count = 10;

    Animal *Animal[count];
    for (int j = 0; j < count / 2; ++j)
    {
        Animal[j] = new Dog();
        Animal[j]->makeSound();
    }
    for (int i = count / 2; i < count; ++i)
    {
        Animal[i] = new Cat();
        Animal[i]->makeSound();
    }


    Dog basic;
    {
        Dog tmp;
    }

    system("leaks Animal");

    return (0); 
}