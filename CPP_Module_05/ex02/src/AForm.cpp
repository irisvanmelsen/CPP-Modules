#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _grade_exec(100), _grade_req(100), _signed(false){
    std::cout << "AForm's default constructor has been called" << std::endl;
}

AForm::AForm(std::string str, int GradeSign, int GradeExec) : _name(str), _grade_exec(GradeSign), _grade_req(GradeExec), _signed(false) {
    std::cout << "AForm Constructor called" << std::endl;
    if (GradeSign < 1 || GradeExec < 1)
        throw GradeTooHighException();
    else if (GradeSign > 150 || GradeExec > 150)
        throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj)
        _signed = obj.is_FormSigned();
    std::cout << "AForm's copy operator has been called" << std::endl;
    return *this;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _grade_exec(obj.get_GradeExec()), _grade_req(obj.get_GradeReq()), _signed(obj._signed){
    *this = obj;
}

AForm::~AForm() {
    std::cout << "AForm's Destructor has been called" << std::endl;
}

const char	*AForm::GradeTooHighException::what() const throw(){
		return ("Grade is Too High!");
}	

const char	*AForm::GradeTooLowException::what() const throw(){
		return ("Grade is Too Low!");
}

void	AForm::beSigned(Bureaucrat &Bureau){
	if (Bureau.getGrade() > _grade_req){
		std::cout << "AForm is not yet signed!" << std::endl;
		throw GradeTooLowException();
	}
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->get_GradeExec())
	{
		std::cout << _name << "can't be executed :( !" << std::endl;
		throw GradeTooLowException();
	}
	if (this->is_FormSigned() == false) {
		throw AForm::ExecuteException();
	}
	else {
		exe();
		std::cout << _name << "is executed :) !" << std::endl;
	}
}

const std::string& AForm::getName() const {
	return _name;
}

int	AForm::get_GradeReq() const {
	return _grade_req;
}

int	AForm::get_GradeExec() const {
	return _grade_exec;
}

bool AForm::is_FormSigned() const {
	return _signed;
}

std::ostream	&operator<<(std::ostream &out, AForm &obj){
     return (out << obj.getName() << " has sign grade: " << obj.get_GradeReq() << "and has exec grade: " << obj.get_GradeExec());
}