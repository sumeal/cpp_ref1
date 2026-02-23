#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern& Intern::operator=(Intern const & other)
{
	(void)other;
	return (*this);
}

AForm *Robot(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Shrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *President(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
	AForm*(*functions[])(std::string) = {&Robot, &Shrub, &President};
	std::string array[] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	std::string lowerType;
	for (int i = 0; i < (int)type.length(); i++)
	{
		lowerType += std::tolower(type[i]);
	}
	int i = 0;
	while (i < 3 && array[i].compare(lowerType))
	{
		i++;
	}
	if (i == 3)
		throw (InvalidFormException());
	AForm *form = functions[i](target);
	return (form);
}

const char* Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form name");
}


