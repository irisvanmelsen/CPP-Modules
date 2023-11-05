
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    Weapon::type = type;
}

std::string const &Weapon::getType()
{
    return type;
}

void    Weapon::setType(std::string type)
{
    Weapon::type = type;
}