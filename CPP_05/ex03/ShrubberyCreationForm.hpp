#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};