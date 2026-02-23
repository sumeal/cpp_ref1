#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other), _target(other.getName())
{

}

std::string RobotomyRequestForm::getTarget()
{
	return (_target);
}

void RobotomyRequestForm::activity() const
{
	std::cout << "Drilling noise" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << _target << " has been successfully robotomized" << std::endl;
	}
	else
	{
		std::cout << _target << " has failed to robotomized" << std::endl;
	}
}