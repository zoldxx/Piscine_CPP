#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->inventaire[i] = NULL;
    std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    for (int i = 0; i < 4; i++)
        this->inventaire[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventaire[i])
            delete this->inventaire[i];
        if (src.inventaire[i])
            this->inventaire[i] = src.inventaire[i]->clone();

        // if (!this->inventaire[i] && src.inventaire[i])
        //     exit (1);
    }
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {

        if (this->inventaire[i])
        {
            delete this->inventaire[i];
            this->inventaire[i] = NULL;
        }
    }
     std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource & src)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventaire[i])
            delete this->inventaire[i];
        if (src.inventaire[i])
            this->inventaire[i] = src.inventaire[i]->clone();
    }
     std::cout << "MateriaSource Copy assignment operator called" <<std::endl;
     return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;
    while (i < 4 && this->inventaire[i])
        i++;
    if (i == 4)
        return ;
    this->inventaire[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < 4)
    {
        if (this->inventaire[i])
        {
            if (type == this->inventaire[i]->getType())
            break ;
        }
        i++;
    }
    if (i == 4)
        return (0);
    return (this->inventaire[i]);
}
