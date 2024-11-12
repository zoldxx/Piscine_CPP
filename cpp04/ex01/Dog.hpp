#pragma once
#include <iostream>
#include <string.h>
#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    public:
    Dog(void);
    Dog(Dog const & src);
    ~Dog(void);
    Dog &operator=(Dog const & src);
    
    void makeSound(void) const;
    void put_ideas_in_brain(int i, std::string idea);
    std::string print_ideas(int i) const;

    private:
    Brain *head;
};