#include "PhoneBook.hpp"

#include <sstream>

PhoneBook::PhoneBook() : _mIndex(0) , _size(0){};
PhoneBook::~PhoneBook(){};


int is_digit(std::string s)
{
    int i = -1;

    while (s[++i])
    {
        if (!(s[i] >= 48 && s[i] <= 57))
        {
            std::cout << "Phone number must contain only digits\n";
            return (-1);
        }
    }
    return (0);
}

int check_is_empty(std::string s)
{
    if (s.length() == 0)
    {
        std::cout << "Your data is empty" << std::endl;
        return (-1);
    }
    return (0);
}

int is_uppercase(std::string s)
{
    if (!(s[0] >= 65 && s[0] <= 90))
    {
        std::cout << "The name must start with uppercase" << std::endl;
        return (-1);
    }
    return (0);
}

bool    PhoneBook::get_data(std::string data[5])
{
    std::cout << "Enter first name -> ";
    getline(std::cin, data[0]);
    if (check_is_empty(data[0]) == -1 || is_uppercase(data[0]))
        return (false);
    std::cout << "Enter last name -> ";
    getline(std::cin, data[1]);
    if (check_is_empty(data[1]) == -1 || is_uppercase(data[1]))
        return (false);
    std::cout << "Enter nickname -> ";
    getline(std::cin, data[2]);
    if (check_is_empty(data[2]) == -1)
        return (false);
    std::cout << "Enter phone number -> ";
    getline(std::cin, data[3]);
    if (is_digit(data[3]) == -1 || check_is_empty(data[3]) == -1)
        return (false);
    std::cout << "Enter darkest secret -> ";
    getline(std::cin, data[4]);
    if (check_is_empty(data[4]) == -1)
        return (false);
    return (true);
}

void    PhoneBook::set_data(std::string data[5])
{
    contact[_mIndex].setFirstName(data[0]);
    contact[_mIndex].setLastName(data[1]);
    contact[_mIndex].setNickName(data[2]);
    contact[_mIndex].setPhoneNumber(data[3]);
    contact[_mIndex].setDarkestSecret(data[4]);
    _mIndex++;
    if (_mIndex > 7)
        _mIndex = 0;
    if (_size < 8)
        _size++;
}

void    PhoneBook::ADD(void)
{
    std::string data[5];

    if (get_data(data) == false)
        return ;
    set_data(data);
}

void    PhoneBook::put_vertical_line(std::string s)
{
    if (s.length() > 10)
        std::cout << s.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << s << "|";
}

void    PhoneBook::print_search()
{
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"; 
    std::cout << std::setw(10) << "First name" << "|"; 
    std::cout << std::setw(10) << "Last name" << "|"; 
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl ; 
    for (int i = 0; i < _size; ++i)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        put_vertical_line(contact[i].getFirstName());
        put_vertical_line(contact[i].getLastName());
        put_vertical_line(contact[i].getNickName());
        std::cout << std::endl;
    }
}

void    PhoneBook::show_search_data(int index)
{
    std::cout << "First name = " << contact[index].getFirstName() << std::endl;
    std::cout << "Last name = " << contact[index].getLastName() << std::endl;
    std::cout << "Nickname = " << contact[index].getNickName() << std::endl;
    std::cout << "Phone number = " << contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret = " << contact[index].getDarckestSecret() << std::endl;
}

void    PhoneBook::SEARCH()
{
    print_search();
    std::string indexString ;
    int index ;
    std::cout << "Please insert index -> ";
    getline(std::cin, indexString);

    int i = -1;
    while (indexString[++i])
    {
        if (!(indexString[i] >= 48 && indexString[i] <= 57))
        {
            std::cout << "Phone number must contain only positive integers" << std::endl;
            return ;
        }
        if (indexString.length() == 0)
        {
            std::cout << "Enter index" << std::endl;
            return ;
        }
    }

    std::stringstream ss(indexString);
    ss >> index;
    if (index >= _size || index < 0)
    {
        std::cout << "You entered greater or lower index than expected" << std::endl;
        return ;
    }
    show_search_data(index);
}