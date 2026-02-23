#ifndef AFORM_HPP
#define AFORM_HPP

	#include "Bureaucrat.hpp"
	#include "string"
	#include "iostream"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int toSign, int toExec);
		virtual ~AForm();
		AForm(const AForm& other);
		
		const std::string	getName() const;
		bool				getSigned() const;
		int			getRequiredToSign() const;
		int			getRequiredToExec() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void				signAForm(Bureaucrat& bureaucrat);
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

		void execute(Bureaucrat const &executor) const;
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		virtual void activity() const = 0;

	private:
		AForm();
		AForm& operator=(const AForm& other);
		const std::string _name;
		bool _signed;
		int _requiredToSign;
		int _requiredToExec;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);


#endif