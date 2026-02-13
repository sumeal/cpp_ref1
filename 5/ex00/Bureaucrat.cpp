#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade <= 0)
		throw(GradeTooHighException());
	else if (grade >= 151)
		throw(GradeTooLowException());
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

void Bureaucrat::increment_Grade()
{
	if (_grade - 1 <= 0)
		throw (GradeTooHighException());
	_grade--;

}

void Bureaucrat::decrement_Grade()
{
	if (_grade + 1 >= 151)
		throw (GradeTooLowException());
	_grade++;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

std::ostream& operator<<(std::ostream& out,const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out); 
}

void	Bureaucrat::safe_Increment(Bureaucrat& man)
{
	try
	{
		man.increment_Grade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::safe_Decrement(Bureaucrat& man)
{
	try
	{
		man.decrement_Grade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
