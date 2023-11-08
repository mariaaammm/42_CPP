#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(0), _signGrade(100), _executeGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_signed = other._signed;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    std::cout << "AForm parameter constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& output, const AForm &form)
{
    output << "*********************************" << std::endl;
    output << "Form name             -> " << form.getFName() << std::endl;
    output << "Signed status of form -> " << form.getSigned() << std::endl;
    output << "Sign grade            -> " << form.getSignGrade() << std::endl;
    output << "Execute grade         -> " << form.getExecuteGrade() << std::endl;
    output << "*********************************" << std::endl;
    return (output);
}

const char	*AForm::GradeTooHighException::what() const throw() 
{ 
	return ("The grade is way too high. It must be >= 1");
}
const char	*AForm::GradeTooLowException::what() const throw() 
{
	return ("The grade is way too low. It must be <= 150");
}
const char	*AForm::IsNotExecutedException::what() const throw()
{
	return ("Execution failed");
};
std::string AForm::getFName() const {return (_name);}
bool  AForm::getSigned() const {return (_signed);}
int  AForm::getSignGrade() const {return (_signGrade);}
int  AForm::getExecuteGrade() const {return (_executeGrade);}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (_signed)
        std::cout << "Already signed"  << std::endl;
    if (_signGrade >= bureaucrat.getGrade())
        _signed = true;
    else
        throw GradeTooLowException();
}
