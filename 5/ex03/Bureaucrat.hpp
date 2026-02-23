#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

 #include "string"
 #include "iostream"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		std::string		getName() const;
		int				getGrade() const;
		void			increment_Grade();
		void			decrement_Grade();
		void			safe_Increment(Bureaucrat& man);
		void			safe_Decrement(Bureaucrat& man);
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
		void executeForm(AForm const &form) const;
	private:
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string const	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif