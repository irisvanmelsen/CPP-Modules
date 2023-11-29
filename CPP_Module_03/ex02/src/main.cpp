
#include "FragTrap.hpp"

int main(void)
{
    // ClapTrap Clapton("Evil Clapton");
    ClapTrap Clapton;

    ScavTrap Scavton;

    FragTrap Fragton;

    Clapton.attack("Evil-Clapton");
    Clapton.takeDamage(2);
    Clapton.beRepaired(1);
    Clapton.attack("Evil-Clapton");

    Scavton.attack("Evil-Scavton");
    Scavton.takeDamage(2);
    Scavton.beRepaired(1);
    Scavton.attack("Evil-Scavton");

    Fragton.attack("Evil-Fragton");
    Fragton.takeDamage(2);
    Fragton.beRepaired(1);
    Fragton.attack("Evil-Fragton");
	Fragton.highFivesGuys();

    return (0);
}