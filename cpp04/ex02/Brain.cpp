#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain(void)
{
     std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const & src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i].assign(src.ideas[i]);
     std::cout << "Brain Copy assignment operator called" <<std::endl;
     return (*this);
}

void Brain::put_ideas_in_brain(int i, std::string idea)
{   
    if (i < 100)
        this->ideas[i] = idea;
    return ;
}

std::string Brain::print_ideas(int i)
{
    if (i < 100)
        return (this->ideas[i]);
    return (NULL);
}

