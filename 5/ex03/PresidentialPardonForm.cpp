#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other), _target(other.getName())
{

}

std::string PresidentialPardonForm::getTarget()
{
	return (_target);
}

void PresidentialPardonForm::activity() const
{

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}