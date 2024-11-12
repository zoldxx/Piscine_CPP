#pragma once
#include <iostream>
#include <string.h>
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
    public:
    Cat(void);
    Cat(Cat const & src);
    ~Cat(void);
    Cat &operator=(Cat const & src);
    
    void makeSound(void) const;
    void put_ideas_in_brain(int i, std::string idea);
    std::string print_ideas(int i) const;

    private:
    Brain *head;
};