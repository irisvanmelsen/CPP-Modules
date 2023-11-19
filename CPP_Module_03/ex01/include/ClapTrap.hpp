
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// Members declared as protected are similar to private members but have one key difference.
// They are accessible in derived classes (classes that inherit from the base class).

class ClapTrap {
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();

        // operator 
        ClapTrap &operator=(const ClapTrap &obj);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif