
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap{
    private:
        bool gate_keep;

    public:
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();

        // operator 
        FragTrap &operator=(const FragTrap &obj);

        void highFivesGuys(void);
};

#endif