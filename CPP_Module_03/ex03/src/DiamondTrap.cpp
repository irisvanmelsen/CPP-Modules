
#include "DiamondTrap.hpp"

// This default constructor initializes the name attribute with a default 
// value of "Clapton" if no argument is provided when creating an instance of ClapTrap. 

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrapclap_name")
{
    this->name = "DiamondTrap";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "Default DiamondTrap Constructor called" << std::endl;
}

// This parameterized constructor takes a std::string parameter name and sets the name 
// attribute of the ClapTrap instance to the provided value.

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "clap_name"), FragTrap(), ScavTrap()
{
    this->name = name;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	this->name = obj.name;
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;

	return (*this);
}

void DiamondTrap::status_check()
{
	std::cout << "attack damage: " << this->attack_damage << " energy points: "
	<< this->energy_points <<" hitpoints: " <<this->hit_points << "\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap Name: " << this->name << " ClapTrap Name: " << ClapTrap::name  <<  std::endl;
}