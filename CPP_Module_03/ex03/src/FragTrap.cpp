
#include "FragTrap.hpp"

// This default constructor initializes the name attribute with a default 
// value of "Clapton" if no argument is provided when creating an instance of ClapTrap. 

FragTrap::FragTrap() : ClapTrap()
{
    this->hit_points = ClapTrap::hit_points;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Default FragTrap Constructor called" << std::endl;
}

// This parameterized constructor takes a std::string parameter name and sets the name 
// attribute of the ClapTrap instance to the provided value.

FragTrap::FragTrap(std::string name) : ClapTrap()
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	this->name = obj.name;
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;

	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (this->hit_points == 0)
		std::cout << "FragTrap " << this->name << " has no hp points left to highfive " << std::endl;
    std::cout << "FragTrap " << this->name << " says: highfive anyone?" << std::endl;
}