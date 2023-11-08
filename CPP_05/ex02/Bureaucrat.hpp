#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int	grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			//public:
				/*virtual*/ const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			//public:
				/*virtual*/ const char* what() const throw();
		};

		std::string getName() const;
		int getGrade() const;

		void	increase();
		void	decrease();

		void	signForm(AForm &f);
		void	executeForm(AForm const & form);


	private:
		const std::string 	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat &bureaucrat);