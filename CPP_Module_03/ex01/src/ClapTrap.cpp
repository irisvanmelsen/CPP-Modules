
#include "ClapTrap.hpp"

// This default constructor initializes the name attribute with a default 
// value of "Clapton" if no argument is provided when creating an instance of ClapTrap. 

ClapTrap::ClapTrap()
{
    this->name = "Clapton";
    this->hit_points = 100;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "Default ClapTrap Constructor called" << std::endl;
}

// This parameterized constructor takes a std::string parameter name and sets the name 
// attribute of the ClapTrap instance to the provided value.

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points == 0)
    {
         std::cout << "Claptrap " << this->name << " died earlier already r.i.p ✝." << std::endl;
         return;
    }
    if (this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
            << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points--;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy points left to attack with!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount > this->hit_points)
		this->hit_points = 0;
    if (this->hit_points > 0)
    {
        std::cout << "Claptrap " << this->name << " takes " << amount << " damage points" \
                << std::endl;
        this->hit_points -= amount;
    }
    else
        std::cout << "Claptrap " << this->name << " died earlier already r.i.p ✝." << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hit_points)
    {
        std::cout << "Claptrap " << this->name << " died earlier already r.i.p ✝." << std::endl;
        return;
    }
    if (this->energy_points)
    {
        std::cout << "Claptrap " << this->name << " repairs " << amount << " hit points," \
            <<" which creates a total of " << this->hit_points + amount << " hit points!" << std::endl;
        this->energy_points--;
        this->hit_points += amount;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy points left to repair with!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	this->name = obj.name;
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;

	return (*this);
}