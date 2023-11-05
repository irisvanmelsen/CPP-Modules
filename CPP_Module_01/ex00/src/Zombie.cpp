
#include "Zombie.hpp"

//CONSTRUCT ZOMBIES:

Zombie::Zombie(void)
{
    std::cout << "rose from the grave ☽" << std::endl;
    name = "stackZombie";
}

Zombie::Zombie(std::string zombie_name)
{
    name = zombie_name;
    std::cout << name << " rose from the grave ☽" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed!" << std::endl;
}

//ANNOUNCE:

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}