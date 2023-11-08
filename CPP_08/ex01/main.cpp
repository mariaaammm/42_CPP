#include "Span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return (0);
// }

// int main()
// {
//     Span sp = Span(100);
//     int a[] = {4, 5, 6, 1, 8, 7, 1};

//     try
//     {
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         sp.addNumber(10000);
        
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
//     sp.addRange(a, a + ((sizeof(a)) / sizeof(int)));
//     // sp.print();
//     // std::cout << std::endl;
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     return (0);
// }



int main()
{
    Span sp(5);
    std::vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(9);
    v.push_back(4);

    sp.addRange(v.begin(), v.end());
    sp.print();

}