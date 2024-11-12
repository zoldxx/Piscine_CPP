#pragma once
#include <iostream>
#include <string.h>
#include "Animal.hpp"


class Cat : public Animal
{
    public:
    Cat(void);
    Cat(std::string name);
    Cat(Cat const & src);
    ~Cat(void);
    Cat &operator=(Cat const & src);
    void makeSound(void) const;
};