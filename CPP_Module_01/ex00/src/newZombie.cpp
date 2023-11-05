
#include "Zombie.hpp"

// newZombie:
// If you need Zombie objects to exist outside the scope of the function in which they are \
// created or if you want to manage their lifetime explicitly, you can allocate them on the heap.

Zombie* newZombie(std::string name)
{
    Zombie* new_zombie = new Zombie(name);
    return (new_zombie);
}