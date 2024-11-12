#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Brain.hpp"


class Animal
{
    public:
    Animal(void);
    Animal(Animal const & src);
    virtual ~Animal(void);
    Animal &operator=(Animal const & src);
    virtual void makeSound(void) const = 0 ;
    virtual std::string getType(void) const;
    virtual std::string print_ideas(int i) const = 0;
    virtual void put_ideas_in_brain(int i, std::string idea) = 0;

    protected:
    std::string type;
};
