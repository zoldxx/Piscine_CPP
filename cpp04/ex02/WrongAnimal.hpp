#pragma once
#include <iostream>
#include <string.h>

class WrongAnimal
{
    public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const & src);
    virtual ~WrongAnimal(void);
    WrongAnimal &operator=(WrongAnimal const & src);
    void makeSound(void) const ;
    virtual std::string getType(void) const;


    protected:
    std::string type;
};