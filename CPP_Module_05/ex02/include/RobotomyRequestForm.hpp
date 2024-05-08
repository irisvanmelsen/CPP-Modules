#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

	virtual void exe() const; // allows your application to handle different form types correctly using the same interface
};

#endif