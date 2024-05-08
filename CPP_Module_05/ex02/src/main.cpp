#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// When an exception of type std::runtime_error is thrown
// the catch block catches it as a std::exception
// and then calls what() on it to retrieve the error message

int main(void)
{
    std::cout << std::endl << "----------------" << std::endl;
    std::cout << "CONSTRUCTORS BEING CALLED:" << std::endl;
    std::cout << "----------------" << std::endl;
    Bureaucrat number_one("One", 1); // highest possible grade
    Bureaucrat number_too_low("Boundary", 146);  // too low
	Bureaucrat number_hundred("Hundred", 100); 
    ShrubberyCreationForm shrub("Shrub"); // requires sign 145 exec 137
    RobotomyRequestForm robo("Robot"); // requires sign72, exec 45
    PresidentialPardonForm pres("President"); // requires sign 25, exec 5

    try {
        std::cout << std::endl << "----------------" << std::endl;
        std::cout << "TRYING FORMS:" << std::endl;
        std::cout << "----------------" << std::endl;

		std::cout << std::endl << "SHOULD SIGN:" << std::endl;
        number_one.signForm(pres); // signs cause higher than 25
		std::cout << std::endl << "SHOULD NOT SIGN (TOO LOW):" << std::endl;
        number_too_low.signForm(shrub); // doesn't sign cause too low
		std::cout << std::endl << "SHOULD SIGN:" << std::endl;
        number_one.signForm(robo); // signs cause higher than 72
		std::cout << std::endl << "SHOULD SIGN:" << std::endl;
        number_hundred.signForm(shrub); // signs cause higher than 72

		std::cout << std::endl << "----------------" << std::endl;
        std::cout << "EXECUTING FORMS:" << std::endl;
		std::cout << "----------------" << std::endl;

		std::cout << std::endl << "----------------" << std::endl;
        std::cout << "PRESIDENTIAL:" << std::endl;
		std::cout << "----------------" << std::endl;
		
		std::cout << std::endl << "EXECUTES (1 HIGHER THAN 5): " << std::endl;
        number_one.executeForm(pres); // will sign high enough
		
		std::cout << std::endl << "DOESN'T EXEC (146 IS LOWER THAN 25): " << std::endl;
        number_too_low.executeForm(pres); // doesn't as grade doesn't meet exec grade

		std::cout << std::endl << "----------------" << std::endl;
        std::cout << "ROBOTOMY:" << std::endl;
		std::cout << "----------------" << std::endl;

		std::cout << std::endl << "EXECUTES (1 HIGHER THAN 45): " << std::endl;
        number_one.executeForm(robo); // will sign high enough

		std::cout << std::endl << "DOESN'T EXEC (146 IS LOWER THAN 72): " << std::endl;
        number_too_low.executeForm(robo); // doesn't as grade doesn't meet exec grade

		std::cout << std::endl << "----------------" << std::endl;
        std::cout << "SHRUBBERY:" << std::endl;
		std::cout << "----------------" << std::endl;

		std::cout << std::endl << "DOENS'T EXEC CAUSE IT IS NOT SIGNED: " << std::endl;
        number_one.executeForm(shrub); // will sign high enough

		std::cout << std::endl << "DOESN'T EXEC (146 IS LOWER THAN 72): " << std::endl;
        number_too_low.executeForm(shrub); // doesn't as grade doesn't meet exec grade

		std::cout << std::endl << "EXECUTES (100 HIGHER THAN 137): " << std::endl;
        number_hundred.executeForm(shrub); // will sign high enough

    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	    std::cout << std::endl << "----------------" << std::endl;
        std::cout << "DESTRUCTORS:" << std::endl;
        std::cout << "----------------" << std::endl;
}