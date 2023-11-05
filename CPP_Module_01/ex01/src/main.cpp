
#include "Zombie.hpp"

int main(void)
{
    int i = 0;
    int number_zombies = 3;

    Zombie *hord_of_zombies = zombieHorde(number_zombies, "Mr Zombie Horde");
    while (i < number_zombies)
    {
        hord_of_zombies[i].announce();
        i++;
    }
    delete[] hord_of_zombies;

    return(0);
}