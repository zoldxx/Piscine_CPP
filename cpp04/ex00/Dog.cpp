#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void)
{
     std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog & src)
{
    this->type = src.type;
     std::cout << "Dog Copy assignment operator called" <<std::endl;
     return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wouaf Wouaf" <<std::endl;
}



