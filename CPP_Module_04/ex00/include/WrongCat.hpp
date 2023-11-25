
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &obj);
        void makeSound() const;
};

#endif