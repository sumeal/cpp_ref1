#include "ShrubberyCreationFarm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other), _target(other.getTarget())
{
}

std::string ShrubberyCreationForm::getTarget()
{
	return (_target);
}

void ShrubberyCreationForm::activity()
{
	std::ofstream out;

	out.open((std::string(_target).append("_shrubbery")).c_str(), std::ios::trunc | std::ios::out);
	out << " _                 \n";
    out << "| |                \n";
    out << "| |_ _ __ ___  ___ \n";
    out << "| __| '__/ _ \\/ _ \\\n";
    out << "| |_| | |  __/  __/\n";
    out << " \\__|_|  \\___|\\___| \n";
	out.close();
}