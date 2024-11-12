#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _Hit_points = 100;
    _Energy_points = 50;
    _Attack_damage = 20;
    std::cout << "Scavtrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
    std::cout << "Scavtrap Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap(void)
{
     std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap & src)
{
     std::cout << "Scavtrap Copy assignment operator called" <<std::endl;
     this->_name = src.getName();
     this->_Hit_points = src.getHP();
     this->_Energy_points = src.getEP();
     this->_Attack_damage = src.getAD();
     return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEP() <= 0)
    {
        std::cout << "Scavtrap " << this->getName() << " don't have energy points, he can't attack." <<std::endl;
        return ;
    }
    if (this->getHP() <= 0)
    {
        std::cout << "Scavtrap " << this->getName() << " don't have hit points, he can't attack." <<std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attack " << target << " causing " << this->getAD() << " points of damage ! " <<std::endl;
    this->setEP(this->getEP() - 1);
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
