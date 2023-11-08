#include "MutantStack.hpp"

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3); 
//     mstack.push(5); 
//     mstack.push(737); //[...] mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin(); 
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite) 
//     {
//         std::cout << *it << std::endl;
//         ++it; 
//     }
//     std::stack<int> s(mstack); 
    
//     return (0);
// }


int main()
{
    MutantStack<int> mstack;
    std::cout << "Empty ->\t" << mstack.empty() << std::endl;
    mstack.push(5);
    std::cout << "Top element ->\t" << mstack.top() << std::endl;
    mstack.push(17);
    std::cout << "Top element ->\t" << mstack.top() << std::endl;
    std::cout << "Size ->\t" << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "Size ->\t" << mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    mstack.push(0); 
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack); 

    MutantStack<int>reverse;
    for (int i = 0; i < 5; ++i) 
        reverse.push(i);

    for (MutantStack<int>::reverse_iterator r_iter = reverse.rbegin(); r_iter != reverse.rend(); r_iter++)
        std::cout << "Reverse ->\t" << *r_iter << std::endl;
    
    return (0);
}