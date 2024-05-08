#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// When an exception of type std::runtime_error is thrown
// the catch block catches it as a std::exception
// and then calls what() on it to retrieve the error message

int	main(void)
{
	Intern someRandomIntern;
	Intern someRandomIntern2;
	Intern someRandomIntern3;
	Intern someRandomIntern4;
	AForm* rrf;
	AForm* rrf2;
	AForm* rrf3;
	AForm* rrf4;

	std::cout << std::endl << "----------------" << std::endl;
    std::cout << "TESTS:" << std::endl;
    std::cout << "----------------" << std::endl;
	rrf = someRandomIntern.makeForm("Robotomy", "Bender");
	std::cout << "----------------" << std::endl;
	rrf2 = someRandomIntern2.makeForm("Shrubbery", "Bender2");
	std::cout << "----------------" << std::endl;
	rrf3 = someRandomIntern3.makeForm("Presidential", "Bender3");
	std::cout << "----------------" << std::endl;
	rrf4 = someRandomIntern3.makeForm("FAIL", "FAIL");
	std::cout << "----------------" << std::endl;
}