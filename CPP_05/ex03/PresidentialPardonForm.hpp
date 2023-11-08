#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};