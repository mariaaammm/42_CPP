#include "PhoneBook.hpp"

int main()
{
    std::string av;
    PhoneBook book;

    while (true)
    {
        std::cout << "Enter ADD, SEARCH or EXIT -> ";
        getline(std::cin, av);
        if (std::cin.eof())
            break;
        if (av.compare("ADD") == 0)
            book.ADD();
        else if (av.compare("SEARCH") == 0)
            book.SEARCH();
        else if (av.compare("EXIT") == 0)
            break;
        else
            std::cout << "Command not found" << std::endl;
    }
    return (0);
}