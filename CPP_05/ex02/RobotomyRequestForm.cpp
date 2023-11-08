#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("")
{
    std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target)
{
    std::cout << "Robotomy parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy", 72, 45), _target(copy._target)
{
    std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_target = other._target;
    std::cout << "Robotomy copy assignment oparator called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {return (_target);}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::srand(time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << getFName() << " robotomized succesfully 50% of the time." << std::endl;
}
