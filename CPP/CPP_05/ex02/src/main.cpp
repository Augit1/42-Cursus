#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat highRank("Alice", 1);
        Bureaucrat lowRank("Bob", 150);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Prisoner");

        std::cout << "\n--- Signing and Executing ShrubberyCreationForm ---" << std::endl;
        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);

        std::cout << "\n--- Signing and Executing RobotomyRequestForm ---" << std::endl;
        highRank.signForm(robotomy);
        highRank.executeForm(robotomy);

        std::cout << "\n--- Signing and Executing PresidentialPardonForm ---" << std::endl;
        highRank.signForm(pardon);
        highRank.executeForm(pardon);

        std::cout << "\n--- Bob Tries to Sign and Execute Forms ---" << std::endl;
        lowRank.signForm(shrubbery);
        lowRank.executeForm(shrubbery);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
