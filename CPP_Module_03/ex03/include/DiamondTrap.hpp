
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
		using ScavTrap::energy_points;
		using FragTrap::attack_damage;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();

        // operator 
        DiamondTrap &operator=(const DiamondTrap &obj);

		void status_check();
		using ScavTrap::attack;
        void whoAmI();
};

#endif
