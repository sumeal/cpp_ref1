#ifndef FORM_HPP
#define FORM_HPP

	#include "string"
	#include "iostream"
	#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int toSign, int toExec);
		~Form();
		Form(const Form& other);
		
		const std::string	getName() const;
		bool				getSigned() const;
		int			getRequiredToSign() const;
		int			getRequiredToExec() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void				signForm(Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};


	private:
		Form();
		Form& operator=(const Form& other);
		const std::string _name;
		bool _signed;
		int _requiredToSign;
		int _requiredToExec;
};

std::ostream& operator<<(std::ostream& out, const Form& Form);


#endif