#include "Form.hpp"

Form::Form() : _name("Form"), _grade_exec(100), _grade_req(100), _signed(false){
    std::cout << "Form's default constructor has been called" << std::endl;
}

Form::Form(std::string str, int GradeSign, int GradeExec) : _name(str), _grade_exec(GradeSign), _grade_req(GradeExec), _signed(false) {
    std::cout << "Form Constructor called" << std::endl;
    if (GradeSign < 1 || GradeExec < 1)
        throw GradeTooHighException();
    else if (GradeSign > 150 || GradeExec > 150)
        throw GradeTooLowException();
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj)
        _signed = obj.is_FormSigned();
    std::cout << "Form's copy operator has been called" << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << "Form's Destructor has been called" << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw(){
		return ("Grade is Too High!");
}	

const char	*Form::GradeTooLowException::what() const throw(){
		return ("Grade is Too Low!");
}

void	Form::beSigned(Bureaucrat &Bureau){
	if (Bureau.getGrade() > _grade_req){
		std::cout << "Form is not yet signed!" << std::endl;
		throw GradeTooLowException();
	}
	_signed = true;
}

const std::string& Form::getName() const {
	return _name;
}

int	Form::get_GradeReq() const {
	return _grade_req;
}

int	Form::get_GradeExec() const {
	return _grade_exec;
}

bool Form::is_FormSigned() const {
	return _signed;
}

std::ostream	&operator<<(std::ostream &out, Form &obj){
     return (out << obj.getName() << " has sign grade: " << obj.get_GradeReq() << "and has exec grade: " << obj.get_GradeExec());
}