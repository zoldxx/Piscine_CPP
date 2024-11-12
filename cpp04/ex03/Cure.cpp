#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(Cure const & src)
{
    *this = src;
    std::cout << "Cure Copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
     std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure & src)
{
    this->type = src.type;
     std::cout << "Cure Copy assignment operator called" <<std::endl;
     return (*this);
}

std::string const & Cure::getType(void) const
{
    return(this->type);
}


AMateria	*Cure::clone() const
{
	return (new Cure(*this));
};

void Cure::use(ICharacter& target)
{
     std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


