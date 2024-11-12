#pragma once
#include <iostream>
#include <string.h>
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
    public:
    WrongCat(void);
    WrongCat(std::string name);
    WrongCat(WrongCat const & src);
    ~WrongCat(void);
    WrongCat &operator=(WrongCat const & src);
    void makeSound(void) const;
    std::string getType(void) const;

    protected:
    std::string type;
};