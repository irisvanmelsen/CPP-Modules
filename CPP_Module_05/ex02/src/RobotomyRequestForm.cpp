#include "RobotomyRequestForm.hpp"

//std::srand(static_cast<unsigned int>(std::time(NULL)))
// is used to generate random number with currect time

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm's Constructor has been called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm's Destructor has been called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    _target = obj._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
	std::cout << "RobotomyRequestForm's Copy Constructor has been called" << std::endl;
    *this = obj;
}

void RobotomyRequestForm::exe() const{
	std::cout << "DrrrRrrRriiiiliiing"<<std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (rand() % 2 == 1) // generates a random number and checks if it is odd (50/50 chance)
		std::cout << _target << " robotomization went well :)" <<std::endl;
	else
		std::cout << "robotomization went horribly wrong :(" <<std::endl;
	
}