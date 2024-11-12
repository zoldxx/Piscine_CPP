#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & src);
    ~ScavTrap(void);
    ScavTrap &operator=(ScavTrap const & src);

    void attack(const std::string& target);
    void guardGate(void);
};