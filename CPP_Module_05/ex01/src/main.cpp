#include "Form.hpp"
#include "Bureaucrat.hpp"

// When an exception of type std::runtime_error is thrown
// the catch block catches it as a std::exception
// and then calls what() on it to retrieve the error message

int	main(void)
{
	Bureaucrat	number_one("one", 1);	
	Bureaucrat	number_hundredfifty("hundredfifty", 150);

	Form form;
	try	
	{
		std::cout << std::endl << std::endl << "THIS SHOULD SIGN:" << std::endl;
		std::cout << "----------------" << std::endl;
		Form Form("Form", 150, 150);
		std::cout << "Number One's grade: " << number_one.getGrade() << std::endl;
		number_one.signForm(Form); // this signs cause 1 is higher than 150
		std::cout << Form.is_FormSigned() << std::endl; // returns 1 which is true
		std::cout << std::endl << std::endl << "THIS SHOULD NOT SIGN (TOO HIGH):" << std::endl;
		std::cout << "----------------" << std::endl;
		number_one.Increment(2); // now it is -1 which is too high ( it is < 1)
		std::cout << "Number One's grade: " << number_one.getGrade() << std::endl;
		Form.is_FormSigned();
		number_one.signForm(Form); // too high to sign as an exception!
		Form.is_FormSigned();
	}
	catch(std::exception& e)
	{
		std::cout << std::endl << "****************" << std::endl;
		std::cout << "Exception:" << e.what() << std::endl;
		std::cout << "****************" << std::endl << std::endl;
	}
	try	
	{ 
		std::cout << std::endl << std::endl << "THIS SHOULD SIGN (EQUAL):" << std::endl;
		std::cout << "----------------" << std::endl;
		Form Form("Form", 150, 150);
		number_one.Decrement(149);
		std::cout << "Number One's grade: " << number_one.getGrade() << std::endl;
		Form.is_FormSigned();
		number_one.signForm(Form);
		std::cout << Form.is_FormSigned() << std::endl; // returns 1 which is true
		Form.is_FormSigned();
		std::cout << std::endl << std::endl << "THIS SHOULD NOT SIGN (TOO LOW):" << std::endl;
		std::cout << "----------------" << std::endl;
		number_one.Decrement(150);
		Form.is_FormSigned();
	}
	catch(std::exception& e)
	{
		std::cout << std::endl << "****************" << std::endl;
		std::cout << "Exception:" << e.what() << std::endl;
		std::cout << "****************" << std::endl << std::endl << std::endl;
	}


}