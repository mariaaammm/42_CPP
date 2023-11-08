#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("")
{
    std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout << "Shrubbery parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("Shrubbery", 145, 137), _target(copy._target)
{
    std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_target = other._target;
    std::cout << "Copy assignment oparator called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {return (_target);}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string file = _target + "_shrubbery";
    std::   ofstream   of(file.c_str());
    if (getExecuteGrade() < executor.getGrade())
        throw GradeTooHighException();
    if (of.is_open() && getSignGrade() > executor.getGrade())
    {
        of << "                                                         ." << std::endl;
        of << "                                              .         ;  " << std::endl;
        of << "                 .              .              ;%     ;;   " << std::endl;
        of << "                   ,           ,                :;%  %;   " << std::endl;
        of << "                    :         ;                   :;%;'     .,   " << std::endl;
        of << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
        of << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        of << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        of << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        of << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        of << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        of << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
        of << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
        of << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
        of << "                          `@%%. `@%%    ;@@%;        " << std::endl;
        of << "                            ;@%. :@%%  %@@%;       " << std::endl;
        of << "                              %@bd%%%bd%%:;     " << std::endl;
        of << "                                #@%%%%%:;;" << std::endl;
        of << "                                %@@%%%::;" << std::endl;
        of << "                                %@@@%(o);  . '         " << std::endl;
        of << "                                %@@@o%;:(.,'         " << std::endl;
        of << "                            `.. %@@@o%::;         " << std::endl;
        of << "                               `)@@@o%::;         " << std::endl;
        of << "                                %@@(o)::;        " << std::endl;
        of << "                               .%@@@@%::;         " << std::endl;
        of << "                               ;%@@@@%::;.          " << std::endl;
        of << "                              ;%@@@@%%:;;;. " << std::endl;
        of << "                          ...;%@@@@@%%:;;;;,..    " << std::endl;
        of.close();
    }
    else
        std::cerr << "Error: Shrubbery execution failed" << std::endl;
        //throw AForm::IsNotExecutedException();
}