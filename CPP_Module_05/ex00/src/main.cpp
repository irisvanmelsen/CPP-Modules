#include "Bureaucrat.hpp"

// When an exception of type std::runtime_error is thrown
// the catch block catches it as a std::exception
// and then calls what() on it to retrieve the error message

int	main(void)
{
	Bureaucrat	number_one("one", 1);	
	Bureaucrat	number_hundredfifty("hundredfifty", 150);

	std::cout << std::endl << number_one << std::endl;

	try
	{
		number_one.Decrement(2);
	}
	catch(std::exception& e)
	{
		std::cout << number_one << std::endl;
		std::cout << "Exception:" << e.what() << std::endl;
	}

	std::cout << std::endl << number_one << std::endl;
	std::cout << std::endl << number_hundredfifty << std::endl;
 
	try
	{
		number_hundredfifty.Increment(20);
	}
	catch(std::exception& e)
	{
		std::cout << number_hundredfifty << std::endl;
		std::cout << "Exception:" << e.what() << std::endl;
	}

	std::cout << std::endl << number_hundredfifty << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat	this_should_error("twothousand", 2000);
	}
	catch(std::exception& e)
	{
		std::cout << "Exception:" << e.what() << std::endl;
	}
	
}