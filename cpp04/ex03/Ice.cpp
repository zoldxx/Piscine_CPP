#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(Ice const & src)
{
    *this = src;
    std::cout << "Ice Copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
     std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice & src)
{
    this->type = src.type;
     std::cout << "Ice Copy assignment operator called" <<std::endl;
     return (*this);
}

std::string const & Ice::getType(void) const
{
    return(this->type);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
};

void Ice::use(ICharacter& target)
{
     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


