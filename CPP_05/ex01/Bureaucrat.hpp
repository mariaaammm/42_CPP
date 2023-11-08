#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int	grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string getName() const;
		int 		getGrade() const;

		void	increase();
		void	decrease();

		void	signForm(Form &f);

	private:
		const std::string _name;
		int				  _grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat &bureaucrat);