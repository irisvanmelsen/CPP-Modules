
#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(std::string);
        ~Cat();

        Cat &operator=(const Cat &obj);
        void makeSound() const;
};

#endif