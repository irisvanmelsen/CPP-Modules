#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Bureaucrat.hpp"

// declaring a member function of a class as const indicates that the function
// does not modify the state of the object on which it is called

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
		const int _grade_exec;
		const int _grade_req;
		bool _signed;
    public:
		AForm();
		AForm(std::string, int, int);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
  			  const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
  			  const char *what() const throw();
		};

		void	beSigned(Bureaucrat &Bureau);
		void 	execute(Bureaucrat const &executor) const;
		int		get_GradeSign() const;
		int		get_GradeExec() const;
		int		get_GradeReq() const;
		bool	is_FormSigned() const;

		const std::string&	getName() const;
		};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif