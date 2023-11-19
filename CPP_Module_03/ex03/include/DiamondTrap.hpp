
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();

        // operator 
        DiamondTrap &operator=(const DiamondTrap &obj);

        void whoAmI();
};

#endif