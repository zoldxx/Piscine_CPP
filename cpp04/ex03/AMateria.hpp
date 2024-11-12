#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const & src);
    virtual ~AMateria(void);
    AMateria &operator=(AMateria const & src);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

    protected:
    std::string type;
};
