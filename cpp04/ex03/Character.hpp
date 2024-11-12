#pragma once

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter
{
    public:
    Character(void);
    Character(std::string name);
    Character(Character const & src);
    Character &operator=(const Character & src);
    virtual ~Character(void);
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    private:
    AMateria *inventaire[4];
    std::string name;
};
