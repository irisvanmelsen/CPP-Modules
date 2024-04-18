#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
    std::cout << "PresidentialPardonForm's Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm's Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    std::cout << "PresidentialPardonForm's copy operator has been called" << std::endl;
    *this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	_target = obj._target;
    return *this;
}

void PresidentialPardonForm::execute() const {
    std::cout << this->_target << " have been pardonned by Zaphod Beeblebrox" << std::endl;
}