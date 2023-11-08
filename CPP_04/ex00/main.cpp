#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog() ;
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete i ;
    delete j ;
    delete meta ;

    /*************************************************/
    // const WrongAnimal* w = new WrongAnimal();
    // const WrongCat* c = new WrongCat();
    // std::cout << c->getType() << std::endl; 
    // c->makeSound();
    // delete w;
    // delete c;

    return (0); 
}