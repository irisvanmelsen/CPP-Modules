#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

i->makeSound();
j->makeSound();

delete j;
delete i;

Animal *animal[100];

for (size_t first_half = 0; first_half < 50; first_half++)
    animal[first_half] = new Dog();
for (size_t last_half = 50; last_half < 100; last_half++)
    animal[last_half] = new Cat();
for (size_t i = 0; i < 100; i++)
    delete animal[i];
return 0;
}