#pragma once
#include <iostream>
#include <string.h>
#include "Animal.hpp"


class Dog : public Animal
{
    public:
    Dog(void);
    Dog(std::string name);
    Dog(Dog const & src);
    ~Dog(void);
    Dog &operator=(Dog const & src);
    void makeSound(void) const;
};