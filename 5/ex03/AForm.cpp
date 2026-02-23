#include "AForm.hpp"

AForm::AForm(std::string name, int toSign, int toExec) : _name(name), _requiredToSign(toSign), _requiredToExec(toExec)
{
	_signed = false;
	if (_requiredToSign <= 0 || _requiredToExec <= 0)
		throw(GradeTooHighException());
	else if (_requiredToSign >= 151 || _requiredToExec >= 151)
		throw(GradeTooLowException());
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other) : _name(other.getName()),_signed(other.getSigned()), _requiredToSign(other.getRequiredToSign()), _requiredToExec(other.getRequiredToExec())
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Grade too low");
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getRequiredToSign() const
{
	return (_requiredToSign);
}

int AForm::getRequiredToExec() const
{
	return (_requiredToExec);
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm: " << AForm.getName() << std::endl <<
	"Signed: " << AForm.getSigned() << std::endl;

	return (out);

}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredToSign)
		_signed = true;
	else
		throw (GradeTooLowException());		
}

void AForm::signAForm(Bureaucrat& bureaucrat)
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

void AForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
	{
		throw (FormNotSignedException());
	}
	if (executor.getGrade() > getRequiredToExec())
	{
		throw (GradeTooLowException());
	}
	activity();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("AForm not signed");
}