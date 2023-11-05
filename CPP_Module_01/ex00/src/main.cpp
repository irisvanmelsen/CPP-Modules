
#include "Zombie.hpp"

int main(void)
{
    std::cout << "Creating heapZombie..." << std::endl;
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();

    std::cout << "Creating stackZombie..." << std::endl;
    randomChump("stackZombie");
    
    delete heapZombie;
    return(0);
}