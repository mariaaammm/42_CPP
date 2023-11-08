#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int	grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << name << " parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() 
{ 
	return ("Grade is too high!");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Grade is too low!");
}

std::string Bureaucrat::getName() const {return (_name);};
int Bureaucrat::getGrade() const {return (_grade);}

std::ostream& operator<<(std::ostream& output, const Bureaucrat &bureaucrat)
{
    output << "Bureaucrat's name is " << bureaucrat.getName() << " and the grade is " << bureaucrat.getGrade() << std::endl;
    return (output);
}

void	Bureaucrat::increase()
{
    --_grade;
    if (this->_grade < 1) 
        throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrease()
{
    ++_grade;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::signForm(Form &f) 
{
    try
    {
        f.beSigned(*this);
        std::cout  << getName() << " signed " << f.getFName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}