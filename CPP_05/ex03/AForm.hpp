#pragma once
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const AForm &copy);
        AForm& operator=(const AForm &other);
        AForm(const std::string name, int signGrade, int executeGrade);
        virtual ~AForm();

        std::string getFName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        class GradeTooHighException : public std::exception
		{
			   const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			    const char* what() const throw();
		};
        class IsNotExecutedException : public std::exception
		{
            public:
			    virtual const char* what() const throw();
		};

        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

    private:
        const std::string _name;
        bool              _signed;
        const int         _signGrade;
        const int         _executeGrade;
};

std::ostream& operator<<(std::ostream& output, const AForm &aform);