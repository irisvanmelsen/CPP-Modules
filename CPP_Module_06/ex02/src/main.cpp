#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//rand() is used to generate a series of random numbers. The random number is
// generated by using an algorithm that gives a series of non-related numbers whenever this function is called

Base *generate(void)
{
	int i = rand();
	if (i % 3 == 0)
	{
		std::cout << "returning new BaseA!" << std::endl;
		return (new BaseA);
	}
	if (i % 3 == 1)
	{
		std::cout << "returning new BaseB!" << std::endl;
		return (new BaseB);
	}
	else
	{
		std::cout << "returning new BaseC!" <<std::endl;
		return (new BaseC);
	}
}


// dynamic_cast: Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.
void identify(Base *p)
{
	if (dynamic_cast<BaseA *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<BaseB *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<BaseC *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Incorrect Type!" << std::endl;
}

void identify(Base &p)
{
	try {
		BaseA a = dynamic_cast<BaseA&>(p);
		std::cout << "Base A" << std::endl;
	}
	catch (std::exception const &e) {
		try {
			BaseB b = dynamic_cast<BaseB&>(p);
			std::cout << "Base B" << std::endl;
			}
			catch (std::exception const &e) {
				try {
					BaseC c = dynamic_cast<BaseC&>(p);
					std::cout << "Base C" << std::endl;
					}
					catch (std::exception const &e) {
						std::cout << e.what() << std::endl;
					}
			}
	}
}

//srand is used to initialize random number generators.
// The srand() function sets the starting point for producing a series of pseudo-random integers.

int main(void)
{
	srand((unsigned)time(NULL));
	Base *base = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	std::cout << "pointer: ";
	identify(base);
	std::cout << std::endl << "address: ";
	identify(*base);
	std::cout << "pointer: ";
	identify(base2);
	std::cout << std::endl << "address: ";
	identify(*base2);
	std::cout << "pointer: ";
	identify(base3);
	std::cout << std::endl << "address: ";
	identify(*base3);
	delete base;
	delete base2;
}