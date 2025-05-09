#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 1);

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "garden");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "robot");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Bob");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "test");

        if (shrubbery)
        {
            alice.signForm(*shrubbery);
            alice.executeForm(*shrubbery);
            delete shrubbery;
        }

        if (robotomy)
        {
            alice.signForm(*robotomy);
            alice.executeForm(*robotomy);
            delete robotomy;
        }

        if (pardon)
        {
            alice.signForm(*pardon);
            alice.executeForm(*pardon);
            delete pardon;
        }

        if (unknown)
        {
            alice.signForm(*unknown);
            alice.executeForm(*unknown);
            delete unknown;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

