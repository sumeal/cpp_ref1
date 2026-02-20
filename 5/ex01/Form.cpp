#include "Form.hpp"

Form::Form(std::string name, int toSign, int toExec) : _name(name), _requiredToSign(toSign), _requiredToExec(toExec)
{
	_signed = false;
	if (_requiredToSign <= 0 || _requiredToExec <= 0)
		throw(GradeTooHighException());
	else if (_requiredToSign >= 151 || _requiredToExec >= 151)
		throw(GradeTooLowException());
}

Form::~Form()
{
}

Form::Form(const Form& other) : _name(other.getName()),_signed(other.getSigned()), _requiredToSign(other.getRequiredToSign()), _requiredToExec(other.getRequiredToExec())
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade too low");
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getRequiredToSign() const
{
	return (_requiredToSign);
}

int Form::getRequiredToExec() const
{
	return (_requiredToExec);
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << "Form: " << Form.getName() << std::endl <<
	"Signed: " << Form.getSigned() << std::endl;

	return (out);

}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredToSign)
		_signed = true;
	else
		throw (GradeTooLowException());		
}

void Form::signForm(Bureaucrat& bureaucrat)
{
	try
	{
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << getName();
	}
	catch (std::exception& e)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << getName() << " because " << e.what() << std::endl;
	}
}