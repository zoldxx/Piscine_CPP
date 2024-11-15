#pragma once
#include <iostream>
#include <string.h>

class Animal
{
    public:
    Animal(void);
    Animal(Animal const & src);
    virtual ~Animal(void);
    Animal &operator=(Animal const & src);
    virtual void makeSound(void) const ;
    virtual std::string getType(void) const;


    protected:
    std::string type;
};