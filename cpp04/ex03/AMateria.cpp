#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria(void)
{
     std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria & src)
{
    this->type = src.type;
     std::cout << "AMateria Copy assignment operator called" <<std::endl;
     return (*this);
}

std::string const & AMateria::getType(void) const
{
    return(this->type);
}
