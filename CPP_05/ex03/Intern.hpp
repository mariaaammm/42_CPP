#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &);
        Intern& operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);

        class CouldntMakeForm : public std::exception
        {
            const char *what(void) const throw();
        };
};