#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(void)
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void)
{
     std::cout << "destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap & src)
{
     std::cout << "Copy assignment operator called" <<std::endl;
    //this->_name = src._name;
     this->_name = src.getName();
     this->_Hit_points = src.getHP();
     this->_Energy_points = src.getEP();
     this->_Attack_damage = src.getAD();
     return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getHP(void) const
{
    return(this->_Hit_points);
}

int ClapTrap::getEP(void) const
{
    return(this->_Energy_points);
}

int ClapTrap::getAD(void) const
{
    return(this->_Attack_damage);
}

void ClapTrap::setHP(int const hp)
{
    this->_Hit_points = hp;
}

void ClapTrap::setEP(int const ep)
{
    this->_Energy_points = ep;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() - (int)amount <= 0)
    {
        std::cout << this->getName() << " take too much damage, he's dead :(" <<std::endl;
        this->setHP(0);
    }
    else
    {
        std::cout << this->getName() << " take " << amount << " damage, he only has " << this->getHP() - (int)amount << " now." <<std::endl;
        this->setHP(this->getHP() - amount);
    }
}

 void ClapTrap::attack(const std::string& target)
 {
    if (this->getEP() <= 0)
    {
        std::cout << this->getName() << " don't have energy points, he can't attack." <<std::endl;
        return ;
    }
    if (this->getHP() <= 0)
    {
        std::cout << this->getName() << " don't have hit points, he can't attack." <<std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " attack " << target << " causing " << this->getAD() << " points of damage ! " <<std::endl;
    this->setEP(this->getEP() - 1);
 }

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getEP() <= 0)
    {
        std::cout << this->getName() << " don't have energy points, he can't heal himself." <<std::endl;
        return ;
    }
    if (this->getHP() <= 0)
    {
        std::cout << this->getName() << " don't have hit points, he can't heal himself." <<std::endl;
        return ;
    }
    if (this->getHP() + amount >= 10)
    {
         std::cout << this->getName() << " is full healed !" <<std::endl;
        this->setHP(10);
    }
    else
    {
        std::cout << this->getName() << " was heal of " << amount << " hit point, he has " << this->getHP() + amount << " now." <<std::endl;
        this->setHP(this->getHP() + amount);
    }
    this->setEP(this->getEP() - 1);
}
