
#include "ClapTrap.hpp"

int main(void)
{
    // ClapTrap Clapton("Evil Clapton");
    ClapTrap Clapton;

    Clapton.attack("Evil-Clapton");
    Clapton.takeDamage(2);
    Clapton.beRepaired(1);
    Clapton.attack("Evil-Clapton");
    // Clapton.takeDamage(9);
    // Clapton.attack("Evil-Clapton");

    Clapton.beRepaired(1);
    Clapton.beRepaired(1);
    Clapton.beRepaired(1);
    Clapton.beRepaired(1);
    Clapton.beRepaired(1);
    Clapton.attack("Evil-Clapton");
    Clapton.attack("Evil-Clapton");
    Clapton.attack("Evil-Clapton");
    Clapton.beRepaired(1);

    return (0);
}