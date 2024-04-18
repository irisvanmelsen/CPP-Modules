#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern's default constructor has been called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern's Destructor has been called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj){
	(void)obj;
	return *this;
}

Intern::Intern(const Intern &obj) {
	std::cout << "Intern's copy constructor has been called" << std::endl;
	*this = obj;
}

AForm *Intern::makeForm(std::string form, std::string target){
	std::string forms[] = {"Presidential", "Robotomy", "Shrubbery"};
	if (form.empty() == true)
	{
		std::cout << "No Forms Found!" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < 3; i ++){
		if (form.compare(forms[i])){
			switch(i){
				case 0:
					return (new RobotomyRequestForm(target));
				case 1:
            		return (new ShrubberyCreationForm(target));
				case 2:
            		return (new PresidentialPardonForm(target));
        		default:
            std::cout << "Can't create form :( " << std::endl;
            return NULL;
			}
		}
	}
}