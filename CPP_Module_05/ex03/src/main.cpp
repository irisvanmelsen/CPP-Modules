#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// When an exception of type std::runtime_error is thrown
// the catch block catches it as a std::exception
// and then calls what() on it to retrieve the error message

int	main(void)
{
	std::cout << std::endl << "----------------" << std::endl;
	std::cout << "CONSTRUCTORS BEING CALLED:" << std::endl;
	std::cout << "----------------" << std::endl;
	Bureaucrat number_one("one", 1);
	Bureaucrat number_seventytwo("seventytwo", 72);
	ShrubberyCreationForm Shrub("Shrubbery");
	RobotomyRequestForm Robo("Robot");
	PresidentialPardonForm Pres("President");
	std::cout << std::endl;

	try {
		std::cout << std::endl << "----------------" << std::endl;
		std::cout << "TRYING FORMS:" << std::endl;
		std::cout << "----------------" << std::endl;
		number_one.signForm(Shrub);
		number_one.signForm(Robo);
		number_one.signForm(Robo);
		number_one.executeForm(Pres);
		number_one.executeForm(Robo);
		number_one.executeForm(Robo);
		std::cout << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Exception:" << e.what() << std::endl;
	}
}