#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int choice = rand() % 3; //5

    switch (choice)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p)
{
    if(dynamic_cast <A* >(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast <B* >(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast <C* >(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Error: Casting failed" << std::endl;
}

void identify(Base& p) 
{
    Base b;

    std::cout << "By reference ";
    try 
    {
        b = dynamic_cast<A& >(p);
        std::cout << "A\n";
    }
    catch (...) {}
    try 
    {
        b = dynamic_cast<B& >(p);
        std::cout << "B\n";
    }
    catch (...) {}
    try 
    {
        b = dynamic_cast<C& >(p);
        std::cout << "C\n";
    }
    catch (...) {}
}

int main() 
{
    Base *p;

    srand(time(NULL));

    p = generate();

    Base &a = *p;

    identify(p);
    identify(a);

    delete(p);
    return (0);
}