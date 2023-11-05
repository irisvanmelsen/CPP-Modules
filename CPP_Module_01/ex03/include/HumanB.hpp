
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

// HumanB will not always be armed
// A pointer allows you to represent the absence of a weapon with a null pointer
// indicating that the "Human" doesn't have a weapon.

class HumanB{
    private:
        Weapon *weapon;
        std::string name;

    public:
        HumanB(std::string name);

        void    attack();
        void    setWeapon(Weapon &ref_weapon);
};

#endif