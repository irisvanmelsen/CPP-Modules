
#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap Clapton("Evil Clapton");
    ClapTrap Clapton;

    ScavTrap Scavton;
    Scavton.attack("Evil-Scavton");
    Scavton.takeDamage(2);
    Scavton.beRepaired(1);
    Scavton.attack("Evil-Clapton");

    Clapton.attack("Evil-Clapton");
    Clapton.takeDamage(2);
    Clapton.beRepaired(1);
    Clapton.attack("Evil-Clapton");



    return (0);
}