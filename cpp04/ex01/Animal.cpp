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

void Animal::makeSound(void) const
{
    std::cout << "..." << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
    return(this->type);
}

void Animal::put_ideas_in_brain(int i, std::string idea)
{
    (void) i;
    (void) idea;
    return ;
}

std::string Animal::print_ideas(int i) const
{
        (void) i;

    return (NULL);
}


