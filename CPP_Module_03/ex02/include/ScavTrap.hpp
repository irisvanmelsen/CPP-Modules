
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    private:
        bool gate_keep;

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        // operator 
        ScavTrap &operator=(const ScavTrap &obj);

        void attack(const std::string& target);

        void guardGate();
};

#endif