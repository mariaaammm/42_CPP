#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // AAnimal a;

    int count = 4;

    AAnimal *animal[count];
    for (int j = 0; j < count / 2; ++j)
        animal[j] = new Dog();
    for (int i = count / 2; i < count; ++i)
        animal[i] = new Cat();

    animal[0]->makeSound();
    animal[1]->makeSound();
    animal[3]->makeSound();

    for (int i = 0; i < count; ++i)
    {
        delete animal[i];
    }

    //system("leaks AAnimal");

    return 0;
}
