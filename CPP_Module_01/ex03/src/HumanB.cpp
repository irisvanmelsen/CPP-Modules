
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    HumanB::name = name;
    HumanB::weapon = nullptr;
}

void    HumanB::setWeapon(Weapon &ref_weapon)
{
    weapon = &ref_weapon;
}

void    HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << "engages in a knuckle fight!" << std::endl;
}