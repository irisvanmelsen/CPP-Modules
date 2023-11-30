
#include "ScavTrap.hpp"

// This default constructor initializes the name attribute with a default 
// value of "Clapton" if no argument is provided when creating an instance of ClapTrap. 

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hit_points = ClapTrap::hit_points;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->gate_keep = false;
    std::cout << "Default ScavTrap Constructor called" << std::endl;
}

// This parameterized constructor takes a std::string parameter name and sets the name 
// attribute of the ClapTrap instance to the provided value.

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    this->name = name;
    this->hit_points = ClapTrap::hit_points;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->gate_keep = false;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points == 0)
    {
         std::cout << "ScavTrap " << this->name << " died earlier already r.i.p ✝." << std::endl;
         return;
    }
    if (this->energy_points > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " \
            << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy points left to attack with!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void    ScavTrap::guardGate()
{
	if (this->hit_points == 0)
		std::cout << "ScavTrap " << this->name << " has no hp left to be in Gate keeper mode" << std::endl;
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
    this->gate_keep = true;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	this->name = obj.name;
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;

	return (*this);
}