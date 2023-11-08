#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int	grade) : _name(name)
{
    _grade = grade;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << name << " parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() 
{ 
	return ("The grade must be <= 150");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("The grade must be > 0");
}

std::string Bureaucrat::getName() const {return (_name);};
int Bureaucrat::getGrade() const {return (_grade);}

std::ostream& operator<<(std::ostream& output, const Bureaucrat &bureaucrat)
{
    output << "Name is " << bureaucrat.getName() << " and the grade is " << bureaucrat.getGrade();
    return (output);
}

void	Bureaucrat::increase()
{
    --_grade;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrease()
{
    ++_grade;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooHighException();
}