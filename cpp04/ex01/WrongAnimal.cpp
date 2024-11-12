#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void)
{
     std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal & src)
{
    this->type = src.type;
     std::cout << "WrongAnimal Copy assignment operator called" <<std::endl;
     return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "..." << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return(this->type);
}

