#ifndef AFORM_HPP
#define AFORM_HPP

	#include "string"
	#include "iostream"
	#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(std::string name, int toSign, int toExec);
		~AForm();
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