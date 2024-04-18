#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();

    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);
	AForm *makeForm(std::string form, std::string target);
};

#endif