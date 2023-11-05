
#include "Zombie.hpp"

// randomChump:
// If you know that a Zombie object's lifetime is limited to a specific function \
// or scope and you don't need it to persist beyond that scope, you can allocate it on the stack.

void randomChump(std::string name)
{
    Zombie stackZombie(name);
    stackZombie.announce();
}