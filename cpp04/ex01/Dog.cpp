#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Constructor called" << std::endl;
    this->type = "Dog";
    this->head = new Brain;
    if (!this->head)
        exit(1);
}

Dog::Dog(Dog const & src)
{
    this->type = src.type;
    this->head = new Brain;
    if (!this->head)
        exit(1);
    for (int i = 0; i < 100; i++)
        this->head->put_ideas_in_brain(i, src.print_ideas(i));
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    delete this->head;
     std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog & src)
{
    this->type = src.type;
    this->head = new Brain;
    if (!this->head)
        exit(1);
    for (int i = 0; i < 100; i++)
        this->head->put_ideas_in_brain(i, src.print_ideas(i));
     std::cout << "Dog Copy assignment operator called" <<std::endl;
     return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wouaf Wouaf" <<std::endl;
}

void Dog::put_ideas_in_brain(int i, std::string idea)
{   
    if (i < 100)
        this->head->put_ideas_in_brain(i, idea);
    return ;
}

std::string Dog::print_ideas(int i) const
{
    if (i < 100)
        return (this->head->print_ideas(i));
    return (NULL);
}



