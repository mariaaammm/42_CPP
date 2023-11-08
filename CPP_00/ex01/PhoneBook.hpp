#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook (void);
        ~PhoneBook (void);

        void ADD (void) ;
        void SEARCH (void) ;
    private:
        int     _mIndex;
        int     _size;
        Contact contact[8];
        bool    get_data(std::string data[5]);
        void    set_data(std::string data[5]);
        void    print_search();
        void    show_search_data(int index);
        void    put_vertical_line(std::string s);
};