
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

// HumanA will always be armed
// With a reference, you guarantee that the "Human" always refers to a valid "Weapon" object

class HumanA{
    private:
        Weapon *weapon;
        std::string name;

    public:
        HumanA(std::string name, Weapon &ref_weapon);

        void    attack();
};

#endif