
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// Members declared as public are accessible from any part of the program.
// They can be accessed directly using the object of the class.

class ScavTrap : public virtual ClapTrap
{
    private:
        bool gate_keep;
	protected:
		int attack_damage;
		int energy_points;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        // operator 
        ScavTrap &operator=(const ScavTrap &obj);

		void attack(const std::string& target);
        void guardGate();
};

#endif
