#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice(void);
    Ice(Ice const & src);
    virtual ~Ice(void);
    Ice &operator=(Ice const & src);

    std::string const & getType(void) const; //Returns the materia type
    virtual AMateria* clone(void) const;
    virtual void use(ICharacter& target);

    protected:
};
