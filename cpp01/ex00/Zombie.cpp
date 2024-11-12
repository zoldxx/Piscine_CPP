#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    return ;
}


Zombie::~Zombie(void)
{
    std::cout << this->name << " go back to the ground" << std::endl;
    return ;
}