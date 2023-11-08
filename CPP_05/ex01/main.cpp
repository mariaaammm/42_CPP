#include "Form.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat b("Bob", 35);
        Form f("Form", 40, 60);
        std::cout << f << std::endl;
        std::cout << b << std::endl;
        b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }  
}
