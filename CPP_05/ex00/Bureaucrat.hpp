#pragma once
#include <iostream>

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
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		std::string getName() const;
		int 		getGrade() const;

		void	increase();
		void	decrease();

	private:
		const std::string _name;
		int				  _grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat &bureaucrat);