#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " go back to the ground" << std::endl;
    return ;
}
