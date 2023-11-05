
#include "Zombie.hpp"

//CONSTRUCT ZOMBIES:

void    Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::Zombie(void)
{
    std::cout << "A Zombie rose from the grave ☽" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " has been destroyed!" << std::endl;
}

//ANNOUNCE:

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}