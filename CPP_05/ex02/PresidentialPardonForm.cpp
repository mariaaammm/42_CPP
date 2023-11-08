#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("")
{
    std::cout << "PresidentialPardon default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardon parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardon", 25, 5), _target(copy._target)
{
    std::cout << "PresidentialPardon copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_target = other._target;
    std::cout << "PresidentialPardon copy assignment oparator called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardon destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {return (_target);}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getSigned() && executor.getGrade() < getExecuteGrade())
        std::cout << getFName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        throw AForm::GradeTooLowException();
}