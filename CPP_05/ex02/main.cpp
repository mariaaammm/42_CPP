#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try 
    {
        Bureaucrat bur("Buro", 2);
        Bureaucrat bur2("Buro2", 1);
        Bureaucrat bur3("Buro3", 1);

        PresidentialPardonForm form("P");
        RobotomyRequestForm form2("R");
        ShrubberyCreationForm form3("Sh");

        bur.signForm(form) ;
        bur2.signForm(form2) ;
        bur3.signForm(form3) ;

        bur.executeForm(form) ;
        bur2.executeForm(form2) ;
        bur3.executeForm(form3) ;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl ; 
    }
}
