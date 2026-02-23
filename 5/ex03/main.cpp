#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void testMakeForm(const std::string& formName, const std::string& target, Intern& intern)
{
    std::cout << "\n-- Trying to make form: " << formName << " --\n";
    AForm* form = 0;

    try
    {
        form = intern.makeForm(formName, target);
        std::cout << "Form created: " << form->getName() << " targeting " << target << std::endl;
        
        // Optional: try signing and executing with a high-grade bureaucrat
        Bureaucrat boss("Boss", 1);
        try
        {
            form->beSigned(boss);
            form->execute(boss);
        }
        catch (std::exception& e)
        {
            std::cout << "Execution error: " << e.what() << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Clean up memory
    delete form;
}

int main()
{
    std::srand(std::time(0));

    Intern someIntern;

    // Valid forms
    testMakeForm("shrubbery creation", "HomeGarden", someIntern);
    testMakeForm("robotomy request", "Bender", someIntern);
    testMakeForm("presidential pardon", "Arthur Dent", someIntern);

    // Invalid form
    testMakeForm("unknown form", "Nobody", someIntern);

    return 0;
}