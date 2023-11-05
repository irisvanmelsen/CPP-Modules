
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    while (N > 0)
    {
        N--;
        horde[N].setName(name);
    }

    return (horde);
}