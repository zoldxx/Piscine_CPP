#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(void)
{
     std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat & src)
{
    this->type = src.type;
     std::cout << "WrongCat Copy assignment operator called" <<std::endl;
     return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Wrong Meow Meow" <<std::endl;
}

std::string WrongCat::getType(void) const
{
    return(this->type);
}


