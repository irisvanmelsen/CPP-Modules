
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();

        // operator 
        FragTrap &operator=(const FragTrap &obj);

        void highFivesGuys(void);
};

#endif