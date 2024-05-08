#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

// when an exception object is caught, the what() function is often 
// called to obtain a human-readable description of the error that occurred.

// GradeToo.. functions inherit publicly from std::exception so they get all characteristics
// and functionalities from that class.

// Polymorphic Destruction: When you delete an object through a pointer to its base class
// type, and that base class has a virtual destructor, the correct destructor will be called based on the actual object type. 
// that's why you have to use virtual with the destructor

class Bureaucrat {
    private:
        const std::string _name;
		int			_grade;
    public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat &operator=(const Bureaucrat &obj);
		virtual ~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
  			  const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
  			  const char *what() const throw();
		};

		void	setGrade(int grade);
		void	Increment(int number);
		void	Decrement(int number);	

		std::string	getName() const;
		int	getGrade() const;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);	

#endif