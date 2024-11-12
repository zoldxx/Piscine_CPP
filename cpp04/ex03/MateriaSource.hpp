#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
    MateriaSource(void);
    virtual ~MateriaSource(void);
    MateriaSource(MateriaSource const & src);
    MateriaSource &operator=(const MateriaSource & src);
    virtual void learnMateria(AMateria *m);
    virtual AMateria* createMateria(std::string const & type);

    private:
    AMateria *inventaire[4];
};