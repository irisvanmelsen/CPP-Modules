
#include "DiamondTrap.hpp"

int main(void)
{
    // ClapTrap Clapton("Evil Clapton");
    // ClapTrap Clapton;

    // ScavTrap Scavton;

    // FragTrap Fragton;

    DiamondTrap Diamond;

    // Clapton.attack("Evil-Clapton");
    // Clapton.takeDamage(2);
    // Clapton.beRepaired(1);
    // Clapton.attack("Evil-Clapton");

    // Scavton.attack("Evil-Scavton");
    // Scavton.takeDamage(2);
    // Scavton.beRepaired(1);
    // Scavton.attack("Evil-Scavton");

    // Fragton.attack("Evil-Fragton");
    // Fragton.takeDamage(2);
    // Fragton.beRepaired(1);
    // Fragton.attack("Evil-Fragton");

	Diamond.status_check();
    Diamond.whoAmI();
    Diamond.attack("Evil-Diamond");
    Diamond.takeDamage(2);
    Diamond.beRepaired(1);
    Diamond.attack("Evil-Diamond");
	Diamond.highFivesGuys();
	Diamond.guardGate();

    return (0);
}