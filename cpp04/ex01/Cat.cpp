#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Constructor called" << std::endl;
    this->type = "Cat";
    this->head = new Brain;
    if (!this->head)
        exit(1);
}

Cat::Cat(Cat const & src)
{
    this->type = src.type;
    this->head = new Brain;
    if (!this->head)
        exit(1);
    for (int i = 0; i < 100; i++)
        this->head->put_ideas_in_brain(i, src.print_ideas(i));
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    delete this->head;
     std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat & src)
{
    this->type = src.type;
    this->head = new Brain;
    if (!this->head)
        exit(1);
    for (int i = 0; i < 100; i++)
        this->head->put_ideas_in_brain(i, src.print_ideas(i));
     std::cout << "Cat Copy assignment operator called" <<std::endl;
     return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow Meow" <<std::endl;
}

void Cat::put_ideas_in_brain(int i, std::string idea)
{   
    if (i < 100)
        this->head->put_ideas_in_brain(i, idea);
    return ;
}

std::string Cat::print_ideas(int i) const
{
    if (i < 100)
        return (this->head->print_ideas(i));
    return (NULL);
}

