
#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain's Constructor has been called" << std::endl;
    return;
}

Brain::~Brain(void) {
    std::cout << "Brain's Deconstructer has been called" << std::endl;
    return;
}

Brain::Brain(const Brain& obj) {
    std::cout << "Brain's Copy Constructor has been called" << std::endl;
    *this = obj;
    return;
}

Brain& Brain::operator=(const Brain& obj) {
    std::cout << "Brain's Copy assignment has been called" << std::endl;
    for (size_t amount = 0; amount < 100; amount++)
        this->ideas[amount] = obj.ideas[amount];
    return (*this);
}

