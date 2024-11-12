#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "animal";
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void)
{
     std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal & src)
{
    this->type = src.type;
     std::cout << "Animal Copy assignment operator called" <<std::endl;
     return (*this);
}

std::string Animal::getType(void) const
{
    return(this->type);
}