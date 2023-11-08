#include "Form.hpp"

Form::Form() : _name("default"), _signed(0), _signGrade(100), _executeGrade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        this->_signed = other._signed;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Form::Form(const std::string name, int signGrade, int executeGrade) : _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form parameter constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Form &form)
{
    output << "*********************************" << std::endl;
    output << "Form name             -> " << form.getFName() << std::endl;
    output << "Signed status of form -> " << form.getSigned() << std::endl;
    output << "Sign grade            -> " << form.getSignGrade() << std::endl;
    output << "Execute grade         -> " << form.getExecuteGrade() << std::endl;
    output << "*********************************" << std::endl;
    return (output);
}

const char	*Form::GradeTooHighException::what() const throw() 
{ 
	return ("The grade is way too high.");
}
const char	*Form::GradeTooLowException::what() const throw() 
{
	return ("The grade is way too low.");
}

std::string Form::getFName() const {return (_name);}
bool        Form::getSigned() const {return (_signed);}
int         Form::getSignGrade() const {return (_signGrade);}
int         Form::getExecuteGrade() const {return (_executeGrade);}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (_signed)
        std::cout << "Already signed"  << std::endl;
    if (_signGrade >= bureaucrat.getGrade())
        _signed = true;
    else
        throw GradeTooLowException();
}
