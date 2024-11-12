#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _Hit_points = 100;
    _Energy_points = 100;
    _Attack_damage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void)
{
     std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap & src)
{
     std::cout << "FragTrap Copy assignment operator called" <<std::endl;
    //this->_name = src._name;
     this->_name = src.getName();
     this->_Hit_points = src.getHP();
     this->_Energy_points = src.getEP();
     this->_Attack_damage = src.getAD();
     return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (this->getEP() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " don't have energy points, he can't attack." <<std::endl;
        return ;
    }
    if (this->getHP() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " don't have hit points, he can't attack." <<std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " attack " << target << " causing " << this->getAD() << " points of damage ! " <<std::endl;
    this->setEP(this->getEP() - 1);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap ask for high five between bros !!" << std::endl;
}
