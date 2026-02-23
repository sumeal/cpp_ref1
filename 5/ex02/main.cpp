#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

void testShrubbery()
{
    std::cout << "\n--- Shrubbery Test ---\n";
    ShrubberyCreationForm form("Garden");
    Bureaucrat signer("Ali", 50);
    Bureaucrat executor("Boss", 1);

    try {
        form.beSigned(signer);
        form.execute(executor);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testRobotomy()
{
    std::cout << "\n--- Robotomy Test ---\n";
    RobotomyRequestForm form("Bender");
    Bureaucrat signer("Ali", 40);
    Bureaucrat executor("Chief", 1);

    try {
        form.beSigned(signer);
        form.execute(executor);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testPresidential()
{
    std::cout << "\n--- Presidential Pardon Test ---\n";
    PresidentialPardonForm form("Arthur Dent");
    Bureaucrat signer("Minister", 20);
    Bureaucrat executor("President", 1);

    try {
        form.beSigned(signer);
        form.execute(executor);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testGradeLimits()
{
    std::cout << "\n--- Grade Boundary Test ---\n";
    try {
        Bureaucrat tooHigh("God", 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("Intern", 151);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testNotSignedExecution()
{
    std::cout << "\n--- Execute Without Signing ---\n";
    ShrubberyCreationForm form("Forest");
    Bureaucrat executor("Boss", 1);

    try {
        form.execute(executor);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testSignTooLow()
{
    std::cout << "\n--- Sign Too Low Grade Test ---\n";

    ShrubberyCreationForm form("LowGarden");
    Bureaucrat weak("Intern", 150); // very low authority

    try {
        form.beSigned(weak);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testExecuteTooLow()
{
    std::cout << "\n--- Execute Too Low Grade Test ---\n";

    RobotomyRequestForm form("Target");
    Bureaucrat strong("Boss", 1);
    Bureaucrat weak("Intern", 150);

    try {
        form.beSigned(strong);  // valid signing
        form.execute(weak);     // invalid execution
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testExecuteFormCases()
{
    std::cout << "\n--- ExecuteForm Convenience Tests ---\n";

    Bureaucrat high("Boss", 1);
    Bureaucrat mid("Manager", 50);
    Bureaucrat low("Intern", 150);

    ShrubberyCreationForm shrub("Park");
    RobotomyRequestForm robo("BenderBot");
    PresidentialPardonForm pardon("Ford Prefect");
    ShrubberyCreationForm unsignedForm("SecretGarden");

    // Sign all forms first with high grade
    try
	{
		shrub.beSigned(high);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    try
	{
		robo.beSigned(high);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    try
	{ 
		pardon.beSigned(high);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    // Execute with executeForm()
    std::cout << "\n-- High grade executor --\n";
    high.executeForm(shrub);    // should succeed
    high.executeForm(robo);     // should succeed (random)
    high.executeForm(pardon);   // should succeed

    std::cout << "\n-- Mid grade executor (may fail if grade too low) --\n";
    mid.executeForm(shrub);     // too low grade for execution
    mid.executeForm(robo);      // too low grade for execution
    mid.executeForm(pardon);    // too low grade for execution

    std::cout << "\n-- Low grade executor (should fail) --\n";
    low.executeForm(shrub);
    low.executeForm(robo);
    low.executeForm(pardon);

    std::cout << "\n-- Execute unsigned form --\n";
    high.executeForm(unsignedForm);  // should throw "not signed"
}

int main()
{
    std::srand(std::time(NULL));

    testShrubbery();
    testRobotomy();
    testPresidential();
    testGradeLimits();
    testNotSignedExecution();
    testSignTooLow();
    testExecuteTooLow();
    testExecuteFormCases();

    return (0);
}