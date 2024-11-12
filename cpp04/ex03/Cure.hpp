#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    Cure(void);
    Cure(Cure const & src);
    virtual ~Cure(void);
    Cure &operator=(Cure const & src);

    std::string const & getType(void) const; //Returns the materia type
    virtual AMateria* clone(void) const;
    virtual void use(ICharacter& target);

    protected:
};
