#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    AForm *f;
    Intern intern;
    f = intern.makeForm("ShrubberyCreationForm", "XXX");

    delete f;
    
    system("leaks AForm");
}
