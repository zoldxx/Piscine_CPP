#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const & src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void)
{
     std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat & src)
{
    this->type = src.type;
     std::cout << "Cat Copy assignment operator called" <<std::endl;
     return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow Meow" <<std::endl;
}
