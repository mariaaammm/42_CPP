#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    std::cout << "Intern copy assignmnt operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Destructor called" << std::endl;
}

const char *Intern::CouldntMakeForm::what()const throw() {return ("Intern couldn't make form");}

AForm* Intern::makeForm(std::string name, const std::string target)
{
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i;
    
    for (i = 0; i < 3 && name != forms[i]; ++i){}

    switch(i)
    {
        case 0:
            std::cout << "Intern creates " << "ShrubberyCreationForm" << std::endl;
            return (new ShrubberyCreationForm(target));
            break;
        case 1:
            std::cout << "Intern creates " << "RobotomyRequestForm" << std::endl;
            return (new RobotomyRequestForm(target));
            break;
        case 2:
            std::cout << "Intern creates " << "PresidentialPardonForm" << std::endl;
            return (new PresidentialPardonForm(target));
            break;
        default:
           throw CouldntMakeForm();
    }
}