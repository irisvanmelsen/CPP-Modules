#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "animal.hpp"

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string);
        virtual ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &obj);
        void makeSound() const;
        std::string getType() const;
};

#endif