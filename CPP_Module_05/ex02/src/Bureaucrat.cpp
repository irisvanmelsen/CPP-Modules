#include "Bureaucrat.hpp"

// exception handling allows you to deal with unexpected or exceptional situations in your code.

Bureaucrat::Bureaucrat() : _name("Bureaucrat") {
    std::cout << "Bureaucrat's default constructor has been called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj)
        this->_grade = obj.getGrade();
    std::cout << "Bureaucrat's copy operator has been called" << std::endl;
    return *this;
}

Bureaucrat::Bureaucrat(std::string n, int i) : _name(n) {
    std::cout << "Bureaucrat Constructor called" << std::endl;
    setGrade(i);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat's Destructor has been called" << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
		return ("Grade is Too High!");
}	

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
		return ("Grade is Too Low!");
}

void    Bureaucrat::Increment(int number){
    setGrade(_grade - number);
}

void    Bureaucrat::Decrement(int number){
    setGrade(_grade + number);
}

void	Bureaucrat::setGrade(int grade){
	if (grade <= 150 && grade >= 1)
		_grade = grade;
	else if (grade > 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

std::string	Bureaucrat::getName() const{
	return (_name);
}

int	Bureaucrat::getGrade() const{
	return (_grade);
}

void Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form){
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " due to: " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj){
    return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

