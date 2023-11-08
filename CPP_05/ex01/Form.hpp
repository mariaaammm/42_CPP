#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const Form &copy);
        Form& operator=(const Form &other);
        Form(const std::string name, const int signGrade, const int executeGrade);
        ~Form();

        std::string getFName() const; 
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;

        class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

        void beSigned(Bureaucrat& bureaucrat);

    private:
        const std::string _name;
        bool              _signed;
        const int         _signGrade;
        const int         _executeGrade;
};

std::ostream& operator<<(std::ostream& output, const Form &form);