#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &AForm);
		AForm *makeForm(std::string type, std::string target);
		class InvalidFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

#endif